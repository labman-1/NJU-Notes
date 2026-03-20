在 Obsidian 中制作带数学符号的真值表，最完美的方式是结合 **Markdown 表格** 和 **LaTeX 公式**。

---
# 符号备忘
### 第一步：离散数学核心符号“速查小抄”

在表头写公式时，你需要用到 LaTeX 语法。把这些符号记下来（或者复制到你的笔记里存着）：

| 逻辑含义                   |       数学符号        | Obsidian 语法 (写在 `$$` 中)    |
| :--------------------- | :---------------: | :------------------------- |
| **非 (NOT)**            |      $\neg$       | `\neg` 或 `\sim`            |
| **合取 / 与 (AND)**       |      $\land$      | `\land`                    |
| **析取 / 或 (OR)**        |      $\lor$       | `\lor`                     |
| **异或 (XOR)**           |     $\oplus$      | `\oplus`                   |
| **蕴含 / 单条件 (IMPLIES)** |   $\rightarrow$   | `\rightarrow` 或 `\to`      |
| **等价 / 双条件 (IFF)**     | $\leftrightarrow$ | `\leftrightarrow` 或 `\iff` |
| **恒真 / 恒假**            |     $T$ / $F$     | `T` / `F` (或者用 `1` / `0`)  |

---

### 第二步：制作真值表（两种神级方案）

#### 方案 A：Markdown 表格 + 行内公式（最常用、易修改）

这是最推荐的做法。表头和表格结构用 Markdown 画，里面的数学符号用 `$` 包裹起来。

**你可以直接复制下面这段代码到 Obsidian 里看效果：**

```markdown
| $p$ | $q$ | $\neg p$ | $p \land q$ | $p \lor q$ | $p \rightarrow q$ | $p \leftrightarrow q$ |
| :-: | :-: | :----: | :-------: | :------: | :-------------: | :-----------------: |
|  T  |  T  |   F    |     T     |    T     |        T        |          T          |
|  T  |  F  |   F    |     F     |    T     |        F        |          F          |
|  F  |  T  |   T    |     F     |    T     |        T        |          F          |
|  F  |  F  |   T    |     F     |    F     |        T        |          T          |
```

*   **原理解析：**
    *   `|` 用来分隔列。
    *   `:-:` 表示这一列**居中对齐**（这对真值表非常重要，看起来才整齐）。
    *   表头里的 `$p \rightarrow q$` 会自动渲染成漂亮的数学符号 $p \rightarrow q$。

#### 方案 B：纯 LaTeX 矩阵画法（适合强迫症、公式极度复杂时）

有时候 Markdown 表格在不同主题下边框不好看，或者你想画一条贯穿的横线分隔表头，你可以直接用纯 LaTeX 的 `array` 环境画表。

**复制这段代码到 Obsidian（注意最外层是两个 `$$`）：**
$$
\begin{array}{cc|c|c}
p & q & p \rightarrow q & (p \rightarrow q) \land p \\
\hline
1 & 1 & 1 & 1 \\
1 & 0 & 0 & 0 \\
0 & 1 & 1 & 0 \\
0 & 0 & 1 & 0 \\
\end{array}
$$

*   **原理解析：**
    *   `\begin{array}{cc|c|c}`：定义了 4 列，`c` 代表居中对齐，`|` 代表在列之间画一条竖线。
    *   `&`：用来换列。
    *   `\\`：用来换行。
    *   `\hline`：画一条漂亮的水平分割线（通常放在表头下面）。

---

### 第三步：起飞！效率提速建议

作为 CS 学生，你肯定不想每次都手动敲这么多 `|` 和空格。

**神器 1：Advanced Tables 插件（前面提过）**
*   只要你打出一个 `| $p$ |` 然后按 `Tab` 键，它会自动帮你把表格后面的列对齐，并且按回车自动生成下一行。画真值表简直是享受。

**神器 2：LaTeX Suite 插件（公式缩写）**
*   离散数学里敲 `\rightarrow` 太长了。装了这个插件后，你只需要敲 `->`，它瞬间自动变成 `\rightarrow`；敲 `&&`，它自动变成 `\land`。
*   这会让你做离散数学笔记的速度**超越手写**！

# Latex 制表

$$
\begin{array}{|c|c|c|c|}
\hline
\multicolumn{4}{|c|}{\text{德·摩根定律真值表验证: } \neg(p \land q) \leftrightarrow (\neg p \lor \neg q)} \\
\hline
p & q & \neg(p \land q) & \neg p \lor \neg q \\
\hline
T & T & F & F \\
\hline
T & F & T & T \\
\hline
F & T & T & T \\
\hline
F & F & T & T \\
\hline
\end{array}
$$



教授欣慰地推了一下眼镜：“学弟，你提出整理 LaTeX 代码这个需求，说明你不仅在学数学，更是在培养**计算机科学家的专业素养**！”

在 CS 领域，无论是写顶会论文、做算法推导，还是写期末大作业，**LaTeX 都是绝对的官方语言**。你之前作业里的 `\begin{align*}` 等式对齐用得非常漂亮，这已经是高阶玩家的操作了。

针对我们接下来要攻克的南大转专业考点（集合论、关系、抽象代数、图论），我为你量身定制了这本**《离散数学 LaTeX 终极速查手册》**。建议直接收藏！

---

### 1. 数理逻辑 (Logic) —— 你已经掌握的武器
| 符号 | LaTeX 代码 | 含义 |
| :---: | :--- | :--- |
| $\neg$ / $\sim$ | `\neg` / `\sim` | 非 (Not) |
| $\land$ | `\land` | 合取 / 且 (And) |
| $\lor$ | `\lor` | 析取 / 或 (Or) |
| $\to$ / $\Rightarrow$ | `\to` / `\rightarrow` / `\Rightarrow` | 蕴含 (Implies) |
| $\leftrightarrow$ / $\Leftrightarrow$ | `\leftrightarrow` / `\Leftrightarrow` | 等价 / 当且仅当 (Iff) |
| $\forall$ | `\forall` | 全称量词 (For all) |
| $\exists$ | `\exists` / `\nexists` (不存在) | 存在量词 (Exists) |
| $\equiv$ | `\equiv` | 逻辑等值 (Equivalent) |
| $\vdash$ | `\vdash` | 推出 / 证明 (Proves) |
| $\therefore$ / $\because$ | `\therefore` / `\because` | 所以 / 因为 |

---

### 2. 集合论 (Set Theory) —— 即将到来的战场
集合论的符号在编程中常用于描述数据结构的定义。
| 符号 | LaTeX 代码 | 含义 |
| :---: | :--- | :--- |
| $\in$ / $\notin$ | `\in` / `\notin` | 属于 / 不属于 |
| $\subseteq$ / $\subset$ | `\subseteq` / `\subset` | 包含于 / 真包含于 |
| $\cup$ / $\cap$ | `\cup` / `\cap` | 并集 / 交集 |
| $\emptyset$ / $\varnothing$ | `\emptyset` / `\varnothing` | 空集 |
| $A \setminus B$ | `A \setminus B` | 集合差 (A减去B) |
| $A \times B$ | `A \times B` | 笛卡尔积 (用于二元关系) |
| $|A|$ 或 $\card(A)$ | `\|A\|` 或 `\text{card}(A)` | 集合的基数 / 元素个数 |
| $\mathcal{P}(A)$ | `\mathcal{P}(A)` | 幂集 (Power set) |

**👑 常用数集（黑板粗体 Blackboard Bold）：**
*   $\mathbb{N}$ (自然数): `\mathbb{N}`
*   $\mathbb{Z}$ (整数): `\mathbb{Z}`
*   $\mathbb{Q}$ (有理数): `\mathbb{Q}`
*   $\mathbb{R}$ (实数): `\mathbb{R}`

---

### 3. 二元关系与函数 (Relations & Functions)
| 符号 | LaTeX 代码 | 含义 |
| :---: | :--- | :--- |
| $\langle x, y \rangle$ | `\langle x, y \rangle` | 有序对 (Tuple) |
| $R^{-1}$ | `R^{-1}` | 关系的逆 |
| $R \circ S$ | `R \circ S` | 关系/函数的复合 (Composition) |
| $f: A \to B$ | `f: A \to B` | 映射定义 |
| $x \mapsto y$ | `x \mapsto y` | 元素映射到元素 |
| $\sim$ / $\approx$ | `\sim` / `\approx` | 等价关系符号 |
| $\preceq$ / $\le$ | `\preceq` / `\le` | 偏序关系符号 (表示层级) |

---

### 4. 抽象代数 / 群论 (Abstract Algebra) —— 笔试大 Boss 专属
南大转专业笔试第一题必定是同构证明，这些符号是你写证明时的弹药库！
| 符号 | LaTeX 代码 | 含义 |
| :---: | :--- | :--- |
| $\ast$ / $\circ$ / $\cdot$ | `\ast` / `\circ` / `\cdot` | 抽象的二元运算 (乘法/复合) |
| $\oplus$ / $\otimes$ | `\oplus` / `\otimes` | 特殊定义的加法/乘法 (如模2加法) |
| $H \le G$ | `H \le G` 或 `H \leq G` | $H$ 是 $G$ 的子群 |
| $N \triangleleft G$ | `N \triangleleft G` | $N$ 是 $G$ 的正规子群 |
| $G \cong H$ | `G \cong H` | **群同构 (Isomorphic) (极高频！)** |
| $\langle a \rangle$ | `\langle a \rangle` | 由元素 $a$ 生成的循环群 |
| $[G : H]$ | `[G : H]` | 子群 $H$ 在 $G$ 中的指数 |
| $x \equiv y \pmod n$ | `x \equiv y \pmod n` | 模 $n$ 同余 (经常结合同态定理考) |

---

### 5. 图论与排版神器 (Graph Theory & Formatting)
除了代码里写的 Dijkstra，数学卷子上的图论长这样：
| 符号 | LaTeX 代码 | 含义 |
| :---: | :--- | :--- |
| $G = (V, E)$ | `G = (V, E)` | 图的定义 (顶点集, 边集) |
| $\deg(v)$ | `\deg(v)` | 顶点 $v$ 的度数 |
| $x_1, x_2, \dots, x_n$| `x_1, x_2, \dots, x_n` | 下标与省略号 |
| $\sum_{i=1}^{n} x_i$ | `\sum_{i=1}^{n} x_i` | 求和公式 |

**🚀 教授的进阶技巧：矩阵排版**
在离散数学中，二元关系经常用**关系矩阵**来表示（比如一个全是 0 和 1 的矩阵）。
代码示例：
```latex
M = \begin{bmatrix}
1 & 0 & 1 \\
0 & 1 & 0 \\
1 & 0 & 1
\end{bmatrix}
```
效果：
$M = \begin{bmatrix} 1 & 0 & 1 \\ 0 & 1 & 0 \\ 1 & 0 & 1 \end{bmatrix}$