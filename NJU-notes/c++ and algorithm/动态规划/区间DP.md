## 区间DP引入及例题
区间DP是线性DP的扩展。
学弟，欢迎来到 DP 家族中最优雅、最具有几何美感的分支——**区间 DP**。

如果说线性 DP（如 LIS、LCS）是在一条线上“从左走到右”，那么区间 DP 就是在 **“切蛋糕”** 或者 **“拼积木”**。

它的核心思想是：**大区间的状态，是由内部的小区间推导出来的。**

---

### 一、 核心框架：怎么“遍历”区间？

这是区间 DP 和线性 DP 最大的区别。
*   线性 DP：`for i = 1 to n` （按位置推）
*   区间 DP：**按长度推 (Enumerate by Length)**

**为什么？**
因为 $dp[i][j]$（表示区间 $i$ 到 $j$）通常依赖于比它**短**的区间（比如 $dp[i][k]$ 和 $dp[k+1][j]$）。所以我们必须先算长度为 1 的，再算长度为 2 的，以此类推。

**万能模板（背诵全文）：**
```cpp
// 1. 枚举区间长度 len (从 2 开始，因为长度 1 通常是初始值)
for (int len = 2; len <= n; len++) {
    // 2. 枚举起点 i
    for (int i = 1; i + len - 1 <= n; i++) {
        int j = i + len - 1; // 自动算出终点 j
        
        // 初始化 dp[i][j] (求最小值设为 INF，求最大值设为 0)
        dp[i][j] = INF; 

        // 3. 枚举分割点 k (Cut Point)
        // 将区间 [i, j] 切分成 [i, k] 和 [k+1, j]
        for (int k = i; k < j; k++) {
            // 状态转移方程
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + cost(...));
        }
    }
}
```
**复杂度**：$O(N^3)$。这也意味着区间 DP 的题目数据范围通常 $N \le 300$ 左右（如果是 $N \le 1000$ 通常需要四边形不等式优化，那是省选内容，转专业考试不考）。

---

### 二、 经典 PBL 实战：石子合并

**题目：洛谷 P1880 [NOI1995] 石子合并**
> 操场上有一排石子（$N$ 堆），每堆有一定的重量。
> 每次你可以合并**相邻**的两堆石子，消耗的体力等于两堆石子的重量之和。
> 问：把所有石子合并成一堆，最小体力和最大体力分别是多少？
> **注意**：题目说石子是摆成**圆形**的（首尾相连）。

我们先忽略“圆形”这个条件，只做**直线**版本，最后我教你一个 trick 搞定圆形。

#### 1. 状态定义
$dp[i][j]$：将第 $i$ 堆到第 $j$ 堆石子，合并成一大堆，所需要的**最小代价**。

#### 2. 状态转移（决策）
要想把 $i \dots j$ 变成一堆，**最后一步**一定是把两堆石头碰在一起。
哪两堆？
可能是 `[i]` 和 `[i+1...j]` 合并；
可能是 `[i...i+1]` 和 `[i+2...j]` 合并；
...
可能是 `[i...k]` 和 `[k+1...j]` 合并。

无论 $k$ 在哪里，最后这一步的花费都是一样的：**区间 $[i, j]$ 内所有石子的总重量**。

**方程：**
$$dp[i][j] = \min_{i \le k < j} (dp[i][k] + dp[k+1][j]) + \text{sum}(i, j)$$

*   $dp[i][k]$：左半边合并好的最小代价。
*   $dp[k+1][j]$：右半边合并好的最小代价。
*   $\text{sum}(i, j)$：最后这一合并操作产生的代价。

**前置技能：前缀和**
为了 $O(1)$ 算出 `sum(i, j)`，我们需要维护前缀和数组 `s[i]`。
`sum(i, j) = s[j] - s[i-1]`。

#### 3. 那个 Trick：断环为链
题目说是圆形的，怎么办？
**经典解法**：把数组复制一遍，接在后面！
*   原数组：`1 2 3`
*   新数组：`1 2 3 1 2 3`
*   原来的圆环 $1-2-3$, $2-3-1$, $3-1-2$ 就变成了新数组里的长度为 $N$ 的连续子段。
*   **做法**：在 $2N$ 的数组上跑区间 DP，最后答案在 $dp[1][n], dp[2][n+1], \dots$ 中找。

---

### 三、 代码实现 (P1880)

这段代码包含了**区间 DP 模板**、**前缀和**、**断环为链**三个核心知识点。

```cpp
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 205; // 因为要断环为链，数组开 2 倍！

int a[N];
int s[N]; // 前缀和
int f_min[N][N]; // dp 数组求最小
int f_max[N][N]; // dp 数组求最大

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;

    // 1. 读入并处理“断环为链”
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i + n] = a[i]; // 复制一份接在后面
    }

    // 2. 计算前缀和 (长度要算到 2*n)
    for (int i = 1; i <= 2 * n; i++) {
        s[i] = s[i - 1] + a[i];
    }

    // 3. DP 初始化
    // 长度为 1 的区间合并代价为 0
    // 其他区间，求最小值设为 INF，求最大值设为 0
    // 注意：一定要遍历到 2*n
    /* 
       这里有一个细节：全局变量自动初始化为0，
       所以 f_max 不需要动，但 f_min 需要填 INF。
       f_min[i][i] 需要手动设回 0。
    */
    memset(f_min, 0x3f, sizeof(f_min));
    for (int i = 1; i <= 2 * n; i++) {
        f_min[i][i] = 0;
        f_max[i][i] = 0;
    }

    // 4. 区间 DP 核心 (模板)
    // 第一层：枚举长度
    for (int len = 2; len <= n; len++) { // 只需要求长度到 n 的即可
        // 第二层：枚举起点
        for (int i = 1; i + len - 1 <= 2 * n; i++) {
            int j = i + len - 1; // 终点

            // 第三层：枚举分割点 k
            for (int k = i; k < j; k++) {
                // 计算当前区间的总重量
                int cost = s[j] - s[i - 1];

                // 状态转移
                f_min[i][j] = min(f_min[i][j], f_min[i][k] + f_min[k + 1][j] + cost);
                f_max[i][j] = max(f_max[i][j], f_max[i][k] + f_max[k + 1][j] + cost);
            }
        }
    }

    // 5. 寻找答案
    // 答案是长度为 n 的所有区间中的最值
    int min_ans = INF;
    int max_ans = 0;

    for (int i = 1; i <= n; i++) {
        min_ans = min(min_ans, f_min[i][i + n - 1]);
        max_ans = max(max_ans, f_max[i][i + n - 1]);
    }

    cout << min_ans << endl << max_ans << endl;

    return 0;
}
```

### 🧠 学姐的“防坑”小贴士

1.  **循环顺序**：切记，**先枚举长度 `len`**！如果你先枚举 `i` 和 `j`，当你计算 `dp[1][5]` 时，可能 `dp[2][5]` 还没算出来（它是 `dp[1][5]` 的子问题），逻辑就崩了。
2.  **断环为链数组大小**：一定要开 $2N$！
3.  **前缀和**：`cost` 一定是 `s[j] - s[i-1]`，别写错下标。
4.  **初始化**：求 `min` 时，`dp` 数组必须初始化为极大值，否则 `min` 永远是 0。
## 题2 [P1063 [NOIP 2006 提高组] 能量项链 - 洛谷](https://www.luogu.com.cn/problem/P1063)
同理，不难得出下一道题的解法。
```c++
#include<bits/stdc++.h>
#define MAX 205
using namespace std;
int n,e=0;
int a[MAX];
int energy[MAX][MAX];
int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	a[2 * n + 1] = a[1];
	for (int len = 2;len <= n;len++) {
		for (int i = 1;i + len - 1 <= 2 * n;i++) {
			int j = i + len - 1;
			for (int k = i; k < j;k++) {
				int cost = a[i] * a[k+1] * a[j+1];
				energy[i][j] = max(energy[i][j], energy[i][k] + energy[k + 1][j] + cost);
			}
		}
	}
	for (int i = 1;i <= n;i++) {
		e = max(e, energy[i][i + n-1]);
	}
	cout << e;
	return 0;
}
```
## 题3[P1005 [NOIP 2007 提高组] 矩阵取数游戏 - 洛谷](https://www.luogu.com.cn/problem/P1005)
```c++
#include<bits/stdc++.h>
#define MAX 90
using namespace std;
class BigInt {
public:
	int digit = 0;
	int number[100] = {0}; 
	BigInt() {};
	BigInt(int num) {
		while (num > 0) {
			digit++;
			number[digit] = num % 10;
			num /= 10;
		}
	}
	BigInt operator +(const BigInt& other) const {
		BigInt a;
		int carry = 0;
		int i = 1;
		int maxDigit = max(this->digit, other.digit);
		for (; i <= maxDigit; ++i) {
			int sum = this->number[i] + other.number[i] + carry;
			a.number[i] = sum % 10;
			carry = sum / 10;
		}
		if (carry) {
			a.number[i++] = carry;
		}
		a.digit = i - 1;
		return a;
	}
	BigInt operator +(int other) const {
		return *this + BigInt(other);
	}
	BigInt operator* (int other) const {
		BigInt result = *this;
		int carry = 0;
		for (int i = 1; i <= result.digit; i++) {
			int temp = result.number[i] * other + carry;
			result.number[i] = temp % 10;
			carry = temp / 10;
		}
		int i = result.digit;
		while (carry) {
			result.number[++i] = carry % 10;
			carry /= 10;
		}
		result.digit = i;
		return result;
	}
	bool operator >(const BigInt& other) const {
		if (other.digit != this->digit) return this->digit > other.digit;
		for (int i = this->digit; i >= 1; --i) {
			if (this->number[i] != other.number[i])
				return this->number[i] > other.number[i];
		}
		return false;
	}
	bool operator <(const BigInt& other) const {
		return other > *this;
	}
};
BigInt p2[MAX];
int n, m;
void initPower() {
	p2[0] = BigInt(1);
	for (int i = 1; i <= m; i++) {
		p2[i] = p2[i - 1] * 2; // 用前一个乘 2 得到下一个
	}
}
int matrix[MAX][MAX];
BigInt dp[MAX][MAX] ;
int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	BigInt ans;
	for (int row = 1;row <= n;row++) {
		for (int col = 1;col <= m;col++) {
			cin >> matrix[row][col];
		}
	}
	initPower();
	for (int row = 1;row <= n;row++) {
		//初始化长度为1的区间作为基础
		for (int x = 1;x <= m;x++) {
			dp[x][x] = p2[m]*matrix[row][x];
		}
		for (int len = 2;len <= m;len++) {
			for (int i = 1;i + len - 1 <= m;i++) {
				int j = i + len - 1;
				dp[i][j] = max(dp[i + 1][j] + p2[m - len + 1] * matrix[row][i],
					dp[i][j - 1] + p2[m - len + 1] * matrix[row][j]);
			}
		}
		ans =ans+ dp[1][m];
	}
	do{
		cout << ans.number[ans.digit--];
	} while (ans.digit > 0);
	return 0;
}
```
这道题由于高精度加区间DP我写了一个小时多一些（悲），花了10分钟才发现dp\[x]\[x]里面要乘上最后的2的m次方，这个挺难找的。还有几个点，
一是刚开始没有注意0的输出（第一版会无法输出0）；
二是引入了BigInt twoPower函数，在每次循环里都调用，忽略了这些数不会变，解决方案：打表（预处理）
为了不 TLE，我们需要把“算 2的次幂”这件事，从 O(K)
降维打击成O(1)。
**策略：**  在 main 函数开始 DP 之前，先算好 ，存到一个数组 BigInt p2[90] 里。  后面谁要用 ，直接查 p2[k]，瞬间拿到！