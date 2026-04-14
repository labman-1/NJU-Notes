Bellman-Form算法和它的队列改进版SPFA在一般的正权图上表现不如Dijkstra，很容易被构造的网格图/菊花图hack掉。
但如果题目明确提示图中存在负权边或者需要判断负权环，这时就可以上SPFA。
Bellman-Ford是**全局动态规划**，SPFA在它的基础上用一个`queue`存下被更新的点，用一个`bool in_queue[]`记录节点是否在队列中。每次取队首节点u，更新它的所有邻居v。若v被更新了且v不在队列中，就将v扔进队列。
https://www.luogu.com.cn/problem/P3385
#### 写法一：使用vector较为直观
```c++
#include<bits/stdc++.h>

const int INF= 0x3f3f3f3f;

using namespace std;

struct Edge{

    int v, w;

    Edge(int a, int b) : v(a), w(b) {}

};

int t;

vector<int>head,nxt,cnt;

vector<Edge>to;

vector<bool>inQueue;

vector<int>dist;

void add(int u, int v,int w){

    nxt.push_back(head[u]);

    head[u]=to.size();

    to.push_back(Edge(v,w));

}

void solve(){

    int n,m;

    cin>>n>>m;

    head.assign(n+1,-1);

    inQueue.assign(n+1,false);

    to.clear();

    nxt.clear();

    for(int i = 0;i<m;i++){

        int u,v,w;

        cin>>u>>v>>w;

        if(w>=0){

            add(v,u,w);

        }

        add(u,v,w);

    }

    dist.assign(n+1,INF);

    dist[1]=0;

    queue<int>q;

    q.push(1);

    inQueue[1]=true;

    cnt.assign(n+1,0);

    cnt[1]=1;

    bool neg=0;

    while(!q.empty()){

        int u = q.front();

        q.pop();

        inQueue[u]=false;

        for(int i =head[u];~i;i=nxt[i]){

            Edge e = to[i];

            if(dist[u]+e.w<dist[e.v]){

                dist[e.v]=dist[u]+e.w;

                //the numbers of edges of the shortest path of e.v

                cnt[e.v]=cnt[u]+1;

                if(cnt[e.v]>n){

                        neg=1;

                        break;

                    }

                if(!inQueue[e.v]){

                    q.push(e.v);

                    inQueue[e.v]=true;

                }

            }

        }

        if(neg) break;

    }

    if(neg)cout<<"YES\n";

    else cout<<"NO\n";

}

int main(){

    ios::sync_with_stdio(false);cin.tie(0);

    cin>>t;

    for(int i = 0;i<t;i++){

        solve();

    }

    return 0;

}
```
#### 使用struct封装，并使用静态数组预分配内存，减小调用开销
```c++
#include <iostream>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 2005;      // 最大节点数
const int MAXM = 6005;      // 最大边数 (注意双向边要开2倍，题目m<=3000)

// 将图完全封装为一个 Class / Struct
struct Graph {
    // 静态预分配大数组，避免 vector 的 new/delete 开销
    int head[MAXN];
    int to[MAXM], w[MAXM], nxt[MAXM];
    int tot; // 边内存池的分配指针
    int num_nodes;

    // 初始化/重置函数（替代析构/构造，专治多组数据）
    void init(int n) {
        num_nodes = n;
        tot = 0;
        // 【核心细节】：只清空当前图用到的节点 head，绝对不要遍历到 MAXN！
        for (int i = 1; i <= n; ++i) {
            head[i] = -1;
        }
    }

    // 极速加边
    void addEdge(int u, int v, int weight) {
        to[tot] = v;
        w[tot] = weight;
        nxt[tot] = head[u];
        head[u] = tot++;
    }
};

Graph G; // 实例化一个图

void solve() {
    int n, m;
    cin >> n >> m;
    
    // 1. 初始化图状态
    G.init(n);
    
    // 2. 极速建图
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        if (w >= 0) {
            G.addEdge(v, u, w);
        }
        G.addEdge(u, v, w);
    }

    // 3. 算法所需的状态数组 (在函数内开 vector 也是可以的，但建议复用静态数组)
    vector<int> dist(n + 1, INF);
    vector<int> cnt(n + 1, 0);
    vector<bool> inQueue(n + 1, false);
    queue<int> q;

    dist[1] = 0;
    cnt[1] = 1; // 采用你的逻辑，起点算1个节点
    q.push(1);
    inQueue[1] = true;

    bool has_negative_cycle = false;

    // 4. SPFA 主逻辑
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        inQueue[u] = false;

        // 遍历 u 的所有出边 (链式前向星的经典 for 循环)
        for (int i = G.head[u]; i != -1; i = G.nxt[i]) {
            int v = G.to[i];
            int weight = G.w[i];

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                cnt[v] = cnt[u] + 1;
                
                if (cnt[v] > n) { // 完美触发负环判定
                    has_negative_cycle = true;
                    break;
                }
                
                if (!inQueue[v]) {
                    q.push(v);
                    inQueue[v] = true;
                }
            }
        }
        if (has_negative_cycle) break;
    }

    if (has_negative_cycle) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    // 保护你的 IO 速度
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (cin >> t) {
        while (t--) solve();
    }
    return 0;
}
```