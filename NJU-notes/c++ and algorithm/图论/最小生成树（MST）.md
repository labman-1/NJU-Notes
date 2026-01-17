**场景：** 修路造桥，怎么用最少的钱把所有城市连起来（不需要成环）？
**机试地位：** ⭐⭐⭐（也是重点，但比最短路稍低）

## Kruskal 算法 (克鲁斯卡尔)
*   **人设**：**“精打细算的包工头”**。
*   **一句话原理**：先把所有边按价格排序，从便宜的开始修。如果这条边连起来的两个城市本来不通，就修；如果已经通了，就不修（防止浪费钱造环）。
*   **核心工具**：**并查集 (Union-Find)**。这是实现 Kruskal 的唯一门槛。
*   **记忆点**：贪心加边 + 并查集。
```c++
#include <bits/stdc++.h>
using namespace std;

// 1. 定义边的结构体，方便排序
struct Edge {
    int u, v, w;
    // 重载小于号，用于 sort 排序 (按边权 w 从小到大)
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

const int N = 5005; // 点数
const int M = 200005; // 边数 (注意：Kruskal 存的是所有边，所以数组要开 M)

int fa[N]; // 并查集数组
Edge edges[M]; // 边数组
int n, m;

// 并查集查找 + 路径压缩 (背诵这行!)
int find(int x) {
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

// 并查集合并
void unite(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) fa[rootX] = rootY;
}

void kruskal() {
    // 2. 初始化并查集：每个人是自己的老大
    for (int i = 1; i <= n; i++) fa[i] = i;

    // 3. 核心步骤：对所有边排序
    sort(edges, edges + m);

    long long ans = 0;
    int edges_count = 0; // 记录选了多少条边

    // 4. 遍历每一条边
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        // 核心判断：如果 u 和 v 还没连通
        if (find(u) != find(v)) {
            unite(u, v); // 连起来
            ans += w;    // 计入花费
            edges_count++;
            
            // 优化：如果已经选够了 n-1 条边，树就生成完了，可以提前退出
            if (edges_count == n - 1) break; 
        }
    }

    // 5. 判连通性
    if (edges_count < n - 1) {
        cout << "orz";
    } else {
        cout << ans;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        // 直接存入边数组，不用邻接表
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    kruskal();
    return 0;
}
```

##  Prim 算法 (普里姆)
*   **人设**：**“一种不断扩张的霉菌”**。
*   **一句话原理**：从一个点开始，不断把离当前集合最近的点吸纳进来。
*   **记忆点**：**它长得和 Dijkstra 几乎一模一样！** 只要学会了 Dijkstra，Prim 也就懂了 90%。
```c++
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f; 
const int N = 5005;      


vector<pair<int, int>> adj[N];
int dist[N]; 
bool vis[N];

void prim(int start) {
   
    memset(dist, 0x3f, sizeof(dist)); 
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, start });

    while (!pq.empty()) {
        pair<int, int> curr = pq.top();
        pq.pop();

        int d = curr.first;  
        int u = curr.second; 

        if (vis[u]) continue;//Prim只需要访问一次即可，无需重复访问
        vis[u] = true;

        for (auto edge : adj[u]) {
            int v = edge.first;  // 邻居编号
            int w = edge.second; // 边权 (u到v的距离)

            if ( !vis[v]&&w < dist[v]) {//这三行就是Prim与Dijkstra的不同之处
                dist[v] = w; // 更新距离
                pq.push({ dist[v], v }); // 把更优的 {新距离, v} 扔进堆里
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; 
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        adj[v].push_back({u, w}); 
    }

    prim(1);
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF) {
            cout << "orz";   //特判非联通图
            return 0;
        }
        ans += dist[i];
    }
    cout << ans;
    return 0;
}
```