# Dijkstra
在图论中已经学过了，此处不再赘述。
# A*
在Single source, single target问题中表现得比Dijkstra好很多，但是需要注意启发式的猜测是否满足consistent(一致性) .因为只要满足一致性，就自动满足了 Admissible（可纳性），这样不仅能保证最优解，还能保证算法最高效运行.
下面解释这两个性质。
这里为你整理了一份关于 A* 启发式性质的结构化笔记，并附上了一个**标准、完整且带详细注释的 Java 实现**（基于 2D 网格地图）。

---

### 📝 笔记：A* 算法启发式函数的性质

#### 1. 可纳性 (Admissibility) —— 保证“找得到最优解”
*   **定义公式**：`h(n) ≤ h*(n)`
    *   `h(n)`：你设计的启发式函数估算值。
    *   `h*(n)`：从节点 `n` 到终点的**真实最小代价**。
*   **通俗理解**：**绝不能高估**到达目标的剩余距离。你的猜测必须比实际情况更“乐观”或者相等。
*   **重要性**：这是 A* 算法在**树搜索 (Tree Search)** 中找到**全局最短路径**的必要条件。如果 `h(n)` 高估了，算法可能会因为“嫌弃”最优路径而被误导，错过答案。
*   **常见满足例**：二维网格中只允许上下左右移动时，使用**曼哈顿距离**（Manhattan Distance）。

#### 2. 一致性 (Consistency) —— 保证“跑得足够快”
*   **定义公式**（三角不等式变形）：`h(n) ≤ c(n, n') + h(n')`
    *   `c(n, n')`：从节点 `n` 移动到邻居 `n'` 的实际代价。
    *   `h(n')`：从邻居 `n'` 到终点的估算值。
*   **通俗理解**：**估算值的变化不能比实际路程更突然**。你直接估算去终点的距离，不能比“先走一步到邻居，再从邻居估计去终点”的距离要远。
*   **重要性**：满足一致性（也叫单调性）时，A* 算法在**图搜索 (Graph Search)** 中，节点一旦从优先队列弹出并放入 `closed set`，其最短路径就**确定下来，不会被后续节点更新**。这极大减少了重复探索，保证每一个节点只被扩展一次。
*   **常见满足例**：二维网格的**欧几里得距离**（直线距离）。

#### 3. 两者的关系与核心考点
*   **包含关系**：**`一致性 ⇒ 可纳性`**（满足一致性则自动满足可纳性），但反之不成立。
*   **⚠️ 极重要区分（对应笔记里的图搜索实现）**：
    *   如果你使用带 `closed set` 的图搜索实现（绝大多数工业级实现），**仅仅可纳是不够的**。如果只满足可纳而不满足一致，你有可能把一个节点放入 `closed` 后又发现更好的路径，此时程序必须把节点“复活”并重新加入优先队列，导致效率急剧下降。
    *   **终极建议**：在实际实现 A* 时，尽可能设计一个**既一致又可纳**的启发式函数（如曼哈顿距离、欧氏距离），这能自动获得“保证找到最短路”+“最高效运行”的双重优势。

---

### 💻 Java 代码实现 (基于网格最短路径)

以下代码实现了在一个 0/1 二维网格中（`0`为可走，`1`为障碍物）寻找最短路径。
启发式函数使用了**曼哈顿距离**，它在网格移动中**同时满足可纳性和一致性**。

```java
import java.util.*;

public class AStarPathfinding {

    // 网格方向：上、下、左、右
    private static final int[][] DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    static class Node {
        int x, y;
        double g, h, f; // g:起点到当前代价, h:启发式估价, f = g + h
        Node parent;    // 用于回溯路径

        public Node(int x, int y) {
            this.x = x;
            this.y = y;
            this.g = Double.MAX_VALUE;
            this.h = 0;
            this.f = Double.MAX_VALUE;
        }
    }

    public static List<int[]> findShortestPath(int[][] grid, int[] start, int[] goal) {
        int rows = grid.length, cols = grid[0].length;
        
        // 1. 初始化起点和优先队列 (按照 f 值从小到大排序)
        Node startNode = new Node(start[0], start[1]);
        startNode.g = 0;
        startNode.h = getHeuristic(start, goal);
        startNode.f = startNode.g + startNode.h;

        PriorityQueue<Node> openList = new PriorityQueue<>(Comparator.comparingDouble(a -> a.f));
        openList.add(startNode);

        // 2. 记录已访问的节点（closed set），避免重复扩展
        boolean[][] closedList = new boolean[rows][cols];
        // 记录每个坐标当前最好的节点，用于图中判断重复
        Node[][] allNodes = new Node[rows][cols];
        allNodes[start[0]][start[1]] = startNode;

        while (!openList.isEmpty()) {
            // 3. 弹出 f 值最小的节点
            Node current = openList.poll();

            // 如果到达终点，回溯并返回路径
            if (current.x == goal[0] && current.y == goal[1]) {
                return reconstructPath(current);
            }

            // 标记为已处理 (标准 A* 依靠一致性保证一旦被扩展就绝对最优)
            closedList[current.x][current.y] = true;

            // 4. 遍历当前节点的 4 个邻居
            for (int[] dir : DIRECTIONS) {
                int nx = current.x + dir[0];
                int ny = current.y + dir[1];

                // 边界检查 & 障碍物检查 (假设 1 是障碍物)
                if (nx < 0 || nx >= rows || ny < 0 || ny >= cols || grid[nx][ny] == 1) {
                    continue;
                }

                // 如果已经在 closedList 中，跳过（因为启发式函数一致，该节点已是最优）
                if (closedList[nx][ny]) {
                    continue;
                }

                // 计算从起点到新邻居的代价（假设上下左右移动每步代价为 1）
                double tentativeG = current.g + 1; 

                Node neighbor = allNodes[nx][ny];
                if (neighbor == null) {
                    neighbor = new Node(nx, ny);
                    allNodes[nx][ny] = neighbor;
                }

                // 5. 如果发现到该邻居更短的路径（或者尚未访问过），更新并加入 openList
                if (tentativeG < neighbor.g) {
                    neighbor.parent = current;
                    neighbor.g = tentativeG;
                    neighbor.h = getHeuristic(new int[]{nx, ny}, goal); // 曼哈顿距离（保持一致且可纳）
                    neighbor.f = neighbor.g + neighbor.h;

                    // 如果不在 openList 中（完全新节点），直接加入；如果已存在，优先级队列会自动调整位置
                    openList.add(neighbor); 
                }
            }
        }

        return new ArrayList<>(); // 没有找到路径，返回空列表
    }

    // 启发式函数：曼哈顿距离 (4方向移动下满足 Admissible 和 Consistent)
    private static double getHeuristic(int[] from, int[] to) {
        return Math.abs(from[0] - to[0]) + Math.abs(from[1] - to[1]);
    }

    // 从终点节点向前回溯寻找完整路径
    private static List<int[]> reconstructPath(Node node) {
        List<int[]> path = new ArrayList<>();
        while (node != null) {
            path.add(new int[]{node.x, node.y});
            node = node.parent;
        }
        Collections.reverse(path);
        return path;
    }

    // ================= 测试代码 =================
    public static void main(String[] args) {
        // 0: 可通过, 1: 障碍物
        int[][] grid = {
            {0, 0, 0, 0, 0},
            {0, 1, 1, 0, 0},
            {0, 0, 0, 1, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 0, 0, 0}
        };
        int[] start = {0, 0};
        int[] goal = {4, 4};

        List<int[]> path = findShortestPath(grid, start, goal);
        
        if (!path.isEmpty()) {
            System.out.println("找到最短路径，途经坐标：");
            for (int[] p : path) {
                System.out.println("(" + p[0] + ", " + p[1] + ")");
            }
        } else {
            System.out.println("无法到达终点！");
        }
    }
}
```

**💡 附加实现原理解析**：
1. `PriorityQueue<Node>` 实现了**优先队列**（Open List），每次都能以极低复杂度（O(log n)）拿出 `f` 值最小的节点。
2. `getHeuristic()` 方法使用了曼哈顿距离。在 4 方向网格中，该距离值**绝不会大于实际需要绕障碍物的真实距离（保证了可纳性）**，同时也满足**三角不等式（保证了一致性）**，所以它能触发代码中 `closedList[nx][ny]` 的直接跳过机制，保证了极高效率。
3. `tentativeG < neighbor.g` 的判断标准提供了路径优化更新的能力。