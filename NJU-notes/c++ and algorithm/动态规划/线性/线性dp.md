# https://www.luogu.com.cn/problem/P3009
##  **变量分离与代数提取** 
```c++
#include<bits/stdc++.h>
using namespace std;
constexpr int INF=-0x3f3f3f3f;
int n;
vector<int>p;
int dp[100005];//记录以第i天为结尾的序列中最大利润
int maxVal=0;
int pre[100005];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	p.resize(n+1,0);
	for(int i = 1;i<=n;i++){
		cin>>p[i];
		pre[i]=pre[i-1]+p[i];
	}
	maxVal=INF;
	for(int i=1;i<=n;i++){
		dp[i]=max(pre[i]+maxVal,p[i]);
		maxVal=max(maxVal,dp[i]-pre[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
```
通过代数计算将原本的$O(n^2)$的朴素dp模板优化到了线性复杂度，以上是第一种利用数学化简表达式后的写法，注意可能利润为负数，所以几个变量需要初始化为负无穷以防止0覆盖了正确答案。
## **状态强定义与最优子结构信任**
```c++
#include<bits/stdc++.h>
using namespace std;
constexpr int INF=-0x3f3f3f3f;
int n;
vector<int>p;
int dp[100005];//记录以第i天为结尾的序列中最大利润
int pre[100005];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	p.resize(n+1,0);
	for(int i = 1;i<=n;i++){
		cin>>p[i];
		pre[i]=pre[i-1]+p[i];
	}
	dp[1]=p[1];
	for(int i=1;i<=n;i++){
		dp[i]=max(p[i],dp[i-1]+p[i]);
	}
	int ans=INF;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}
```
以上是第二种写法，发现了内在的数学规律之后写起来十分畅快。其实刚开始我的想法更接近第二种，但是我囿于固定思维，试图套用最长上升子序列的优化方法，同时又错误地认为对于一个新的dp\[i]，需要遍历i前面的所有dp\[j]并加上j到i的区间和取最大值。实际上，dp\[i]要求以第i天作为结尾天然保证了无后效性，而由于dp\[i-1]就是以i-1结尾的最佳选择，所以如果不由dp\[i-1]转移而来，那么绝对不可能由dp\[i-2]等前面的转移而来。写到这里，我想起了分治与递归，它们要求我“信任”子问题已经被很好地处理了，只需不断合并即可。