[P1967 [NOIP 2013 提高组] 货车运输 - 洛谷](https://www.luogu.com.cn/problem/P1967)
本题为无向图，不存在自环，可能有重边，不保证连通性，说明可能为森林。货车最大载重为从城市x到y的所有路径的最小道路限重的最大值，则需要求最大生成树。通过Kruscal对输入的边进行排序然后重构最大生成树，得到新的树/森林，这里保留了所需的所有信息（连通性、路径限重最大值）。  
然后需要进行q次树上查询，朴素的解法复杂度为O(nq)，显然不行。此查询问题等价于查询LCA，通过倍增法可将复杂度降低到(qlogn)。  
易错点：
1. 倍增法的头与尾范围是否正确。比如倍增法，尾巴一定是 2^0 (即 i=0)，如果写成了 i>0，这就叫边界穿透Bug。  
2. 考虑特殊情况（x与y为父子关系）。  
3. 倍增法在跳跃时要取两半中的最值，不能遗漏。
```c++
#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3f3f3f3f;

struct Edge {

    int u, v, w;

    bool operator<(const Edge &other) const { return w < other.w; }

};

bool cmp(const Edge &a, const Edge &b) { return a.w > b.w; }

int n, m;

vector<int> x;

vector<Edge> edges;

vector<pair<int, int>> newGraph[10005];

class DSU {

  private:

    vector<int> f;

    int rk[10005];

  

  public:

    DSU(int n) {

        f.resize(n + 1);

        memset(rk, 0, sizeof(rk));

        for (int i = 0; i <= n; i++) {

            f[i] = i;

        }

    }

    int find(int u) { return f[u] == u ? u : (f[u] = find(f[u])); }

    bool merge(int u, int v) {

        int x = find(u), y = find(v);

        if (x == y)

            return false;

        if (rk[x] <= rk[y])

            f[x] = y;

        else

            f[y] = x;

        if (rk[x] == rk[y])

            rk[y]++;

        return true;
    }
};
// Kruscal 重建树
void Kruscal(DSU &d) {
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back((Edge){x, y, z});
    }
    sort(edges.begin(), edges.end(), cmp);
    int edgeCount = 0;
    for (auto i : edges) {
        if (d.merge(i.u, i.v)) {
            edgeCount++;
            newGraph[i.u].push_back({i.v, i.w});
            newGraph[i.v].push_back({i.u, i.w});
        }
        if (edgeCount == n - 1)
            break;
    }
}
int depth[10005];
int fa[10005][20];
int minWeight[10005][20];
bool visit[10005];
// 倍增法树上搜索

void dfs(int u, int parent, int w) {
    depth[u] = depth[parent] + 1;
    fa[u][0] = parent;
    minWeight[u][0] = w;
    visit[u] = true;
    for (int i = 1; i < 20; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        minWeight[u][i] = min(minWeight[fa[u][i - 1]][i - 1], minWeight[u][i - 1]);
    }
    for (auto edge : newGraph[u]) {
        int v = edge.first, weight = edge.second;
        if (!visit[v]) {
            dfs(v, u, weight);
        }

    }

}

int lacQuery(int x, int y) {
    int ans = INF;
    if (depth[x] < depth[y])
        swap(x, y);
    // 深度对齐
    for (int i = 19; i >= 0; i--) {
        if (depth[fa[x][i]] >= depth[y]) {
            ans = min(ans, minWeight[x][i]);
            x = fa[x][i];
        }
    }
    if (x == y)
        return ans;
    for (int i = 19; i >= 0; i--) {
        if (fa[x][i] != fa[y][i]) {
            ans = min(ans, minWeight[x][i]);
            ans = min(ans, minWeight[y][i]);
            x = fa[x][i];
            y = fa[y][i];
        }
    }
    // 此时x，y位于LCA正下方
    ans = min(ans, minWeight[x][0]);
    ans = min(ans, minWeight[y][0]);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    DSU d(n);
    Kruscal(d);
    int q;
    cin >> q;
    memset(minWeight, INF, sizeof(minWeight));
    for (int i = 1; i <= n; i++) {
        if (!visit[i]) {
            dfs(i, 0, INF);
        }
    }
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        if (d.find(x) != d.find(y))
           cout << -1 << '\n';
        else {
            cout << lacQuery(x, y) << '\n';
        }
    }
    return 0;
}
```