


离散数学（Discrete Mathematics）是 CS 专业的灵魂课程，而**真值表（Truth Table）**更是前几章的核心。

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