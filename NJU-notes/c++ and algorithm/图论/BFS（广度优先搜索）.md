**BFS** 通常用来解 **“迷宫最短路”** 或者 **“最小步数”** 类问题（天然优势）
#### BFS（广度优先）：地毯式搜索

- **性格**：稳重、层层推进。
- 
- **策略**：
    
    1. 先检查离起点只有 1 步的所有房间。
        
    2. 如果没找到，再检查离起点 2 步的所有房间。
        
    3. 以此类推，像水波纹一样扩散。
        
- **数据结构**：**队列 (Queue)**（就是你刚学的 std::queue！）。
    
- **视觉效果**：像水滴入水面，一圈圈向外扩散。
    
- **必杀技**：**BFS 第一次找到目标时，走的路径一定是最短的！**（仅限无权图）。

---

### BFS 代码模板（队列版）

BFS 的核心就是维护一个 `queue`。

**场景**：求起点 `start` 到所有点的**最短距离**（假设每条边长度都是1）。

```cpp
int dist[10005]; // 记录起点到每个点的距离
bool vis[10005]; // 记录是否进过队列
vector<int> adj[10005];

void bfs(int start) {
    // 1. 初始化
    queue<int> q;
    q.push(start);
    vis[start] = true;
    dist[start] = 0; // 起点到自己距离为0

    // 2. 只要队列不空，就一直干活
    while (!q.empty()) {
        int u = q.front(); // 取出队头（当前层的人）
        q.pop();

        // 3. 拓展：把 u 的所有邻居拉进队伍
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;       // 标记进队
                dist[v] = dist[u] + 1; // 距离 = 父节点距离 + 1
                q.push(v);           // 入队，等待下一轮处理
            }
        }
    }
}
```

---

###  实战演练：网格图（Grid Map）

在机试中，更常见的是**二维矩阵地图**（比如迷宫），而不是邻接表。
这时候，我们需要用 `dx, dy` 方向数组来模拟移动。

**方向数组技巧（背下来）：**
```cpp
// 上、下、左、右四个方向的坐标偏移量
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 移动逻辑
for(int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    // 检查 nx, ny 是否越界，是否是墙...
}
```

---



证明：定义如下的映射$f:S_{n}\to A_{n+2}$, $记\sigma 是S_{n}中的任意一个置换,$
$$
f(\sigma)=\begin{cases}
\sigma, &\sigma为偶置换\\ \\
\sigma\circ(n+1,n+2), &\sigma为奇置换
\end{cases}
$$
下证明f为单射。
$\forall \sigma_{1},\sigma_{2}\in S_{n}\land f(\sigma_{1})=f(\sigma_{2}),下面分情况讨论。$
当$\sigma_{1}, \sigma_{2}$中一个为奇置换，一个为偶置换时，显然$f(\sigma_{1})与f(\sigma_{2})$中一个含有对换(n+1,n+2)，另一个不含对换(n+1,n+2)，不符合条件；
当$\sigma_{1}与\sigma_{2}$均为偶置换时，由$f(\sigma_{1})=f(\sigma_{2})$得$\sigma_{1}=\sigma_{2}$.
当$\sigma_{1}与\sigma_{2}$均为奇置换时，由$f(\sigma_{1})=f(\sigma_{2})$得$\sigma_{1}\circ(n+1,n+2)=\sigma_{2}\circ(n+1,n+2)$, 又因为$\sigma_{1}与\sigma_{2}$中不含对换(n+1,n+2)，所以有$\sigma_{1}=\sigma_{2}$.
所以$\forall \sigma_{1},\sigma_{2}\in S_{n},(f(\sigma_{1})=f(\sigma_{2}))\to(\sigma_{1}=\sigma_{2})$, 所以f为单射。
下面证明f满足同态性质。