**场景：** 修路造桥，怎么用最少的钱把所有城市连起来（不需要成环）？
**机试地位：** ⭐⭐⭐（也是重点，但比最短路稍低）

---

### 1. Kruskal 算法（加边法）
*   **核心哲学**：贪心。把所有边按权重从小到大排序，每次挑一条最小的，如果两端点不在同一个集合里，就连起来。
*   **依赖武器**：**并查集 (DSU)** + 排序。
*   **时间复杂度**：$O(E \log E)$ （主要耗在排序上）。
*   **最佳主场**：**稀疏图**（边数 $E$ 接近点数 $V$）。
*   **工程级模板**：

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 边的结构体封装
struct Edge {
    int u, v;
    double w; // 权重（视题目而定，如果是坐标距离常用 double）
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

// 2. 并查集类的完美封装
class DSU {
private:
    vector<int> fa;
public:
    DSU(int n) {
        fa.resize(n + 1);
        for (int i = 0; i <= n; i++) fa[i] = i;
    }
    int find(int x) {
        return fa[x] == x ? x : (fa[x] = find(fa[x]));
    }
    bool merge(int i, int j) {
        int x = find(i), y = find(j);
        if (x == y) return false; // 产生环，拒绝合并
        fa[x] = y;
        return true;              // 合并成功
    }
};

double kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end()); // 按边权排序
    DSU dsu(n);
    
    double mst_weight = 0.0;
    int edge_cnt = 0;
    
    for (const auto& edge : edges) {
        if (dsu.merge(edge.u, edge.v)) {
            mst_weight += edge.w;
            edge_cnt++;
            if (edge_cnt == n - 1) break; // 提前下班的剪枝
        }
    }
    
    if (edge_cnt == n - 1) return mst_weight;
    else return -1.0; // 图不连通
}
```

---

### 2. 堆优化 Prim 算法（加点法）
*   **核心哲学**：阵地扩张。从任意一个起点开始，维护一个“已征服区域”，每次借助优先队列，找到离已征服区域**最近的一个未征服点**，吃掉它，并用它的视野更新周围的点。
*   **依赖武器**：**优先队列 (Priority Queue)** + 邻接表。
*   **时间复杂度**：$O(E \log V)$ （由于堆的维护开销）。
*   **最佳主场**：**稀疏图**，尤其是原本就以“邻接表”形式给出的图。
*   **工程级模板**：

```cpp
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const double INF = 1e18;

// 优先队列里的节点封装：pair<距离, 节点编号>
typedef pair<double, int> pdi;

double prim_heap(int n, const vector<vector<pair<int, double>>>& adj) {
    vector<bool> vis(n + 1, false);
    
    // priority_queue 默认是大根堆，加上 greater 变成小根堆
    priority_queue<pdi, vector<pdi>, greater<pdi>> pq;
    
    double mst_weight = 0.0;
    int node_cnt = 0;
    
    // 从 1 号点开始征服，距离设为 0
    pq.push({0.0, 1});
    
    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        
        if (vis[u]) continue; // 已经被吃掉的点，无视
        
        // 正式征服 u 点
        vis[u] = true;
        mst_weight += w;
        node_cnt++;
        
        if (node_cnt == n) break; // 所有点都被征服，提前下班
        
        // 扩展视野，把邻居塞进优先队列
        for (const auto& edge : adj[u]) {
            int v = edge.first;
            double weight = edge.second;
            if (!vis[v]) {
                pq.push({weight, v});
            }
        }
    }
    
    if (node_cnt == n) return mst_weight;
    else return -1.0;
}
```

---

### 3. 朴素 Prim 算法（加点法的暴力美学）
*   **核心哲学**：同样是阵地扩张。但因为图的边太多了，塞进堆里反而会把堆撑爆导致变慢。所以我们**不存边**，每次直接用一个一维数组 `dist`，写一个 `for` 循环暴力遍历所有点，找出距离最近的点。
*   **依赖武器**：**距离数组 (`dist`)**。
*   **时间复杂度**：严格的 $O(V^2)$。**完全不受边数 $E$ 的影响！**
*   **最佳主场**：**稠密图 / 完全图**（像 P2872 这种点少边极多的情况）。
*   **工程级模板**：
*(注：对于完全图，我们甚至连邻接矩阵都不用开，可以直接在循环里实时计算两点距离，极其节省内存！)*

```cpp
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const double INF = 1e18;

// 假设我们有一个函数能算出 u 和 v 之间的距离（针对 P2872 这种完全图坐标题）
double get_dist(int u, int v); 

double prim_naive(int n) {
    vector<double> dist(n + 1, INF); // 记录每个点到“已征服区域”的最短距离
    vector<bool> vis(n + 1, false);  // 记录是否已被征服
    
    double mst_weight = 0.0;
    
    // 起点初始化
    dist[1] = 0.0;
    
    for (int i = 1; i <= n; i++) {
        // 步骤 1：暴力在未征服的点中，找到距离最小的点 u
        int u = -1;
        double min_d = INF;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dist[j] < min_d) {
                min_d = dist[j];
                u = j;
            }
        }
        
        // 图不连通（或者图有严重问题）
        if (u == -1) return -1.0; 
        
        // 步骤 2：征服点 u
        vis[u] = true;
        mst_weight += dist[u];
        
        // 步骤 3：用 u 的视野去更新其他尚未被征服的点的 dist
        for (int v = 1; v <= n; v++) {
            if (!vis[v]) {
                double w = get_dist(u, v); // 实时计算边权，省下存 V^2 条边的海量内存
                if (w < dist[v]) {
                    dist[v] = w;
                }
            }
        }
    }
    
    return mst_weight;
}
```

---

### 🌟 总结与实战抉择表

把下面这张表刻在脑子里，遇到机试题直接肌肉记忆选型：

| 算法 | 复杂度 | 核心数据结构 | 最佳适用场景 | 致命劣势 |
| :--- | :--- | :--- | :--- | :--- |
| **Kruskal** | $O(E \log E)$ | 并查集 + 排序 | **稀疏图**，或需要直接操作“边”的题目 | 遇到边数 $E$ 到达千万级别时，排序会 TLE 或爆内存 |
| **堆优化 Prim** | $O(E \log V)$ | 优先队列 + 邻接表 | **稀疏图**，图本身就是邻接表格式时 | 在完全图（稠密图）中，优先队列频繁操作导致常数巨大，反受其害 |
| **朴素 Prim** | $O(V^2)$ | 数组 | **稠密图 / 完全图**（如给平面坐标系让连边） | 遇到点数 $V > 10000$ 的稀疏图时，直接 TLE 爆炸 |

针对 **洛谷 P2872** 这道坐标连线题，由于 $N \le 1000$，任意两点皆可连通构成完全图，$E \approx 500,000$。
*   如果你用 **Kruskal**，你需要算 $500,000$ 次平方根，存 $500,000$ 个 `Edge` 对象，然后对这五十万个对象进行 `sort`，非常耗内存和时间。
*   如果你用 **朴素 Prim**，你只需要存 1000 个点的坐标，根本不存边，外层循环 1000 次，在内层循环里实时更新距离，内存接近于 $O(1)$，速度快到飞起！

**学姐经验谈**：
在南大转专业机试或者普通比赛中，**无脑推荐 Kruskal**。
1.  因为它好写，好调试。
2.  `sort` 很快。
3.  它自带“判断图连通性”的功能（看最后选了多少边），不用像 Prim 那样还要检查 `dist`。