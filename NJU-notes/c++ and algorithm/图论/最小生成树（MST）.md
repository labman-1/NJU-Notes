**场景：** 修路造桥，怎么用最少的钱把所有城市连起来（不需要成环）？
**机试地位：** ⭐⭐⭐（也是重点，但比最短路稍低）

## Kruskal 算法 (克鲁斯卡尔)
*   **人设**：**“精打细算的包工头”**。
*   **一句话原理**：先把所有边按价格排序，从便宜的开始修。如果这条边连起来的两个城市本来不通，就修；如果已经通了，就不修（防止浪费钱造环）。
*   **核心工具**：**并查集 (Union-Find)**。这是实现 Kruskal 的唯一门槛。
*   **记忆点**：贪心加边 + 并查集。

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

        if (vis[u]) continue;
        vis[u] = true;

        for (auto edge : adj[u]) {
            int v = edge.first;  // 邻居编号
            int w = edge.second; // 边权 (u到v的距离)

            if ( !vis[v]&&w < dist[v]) {
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