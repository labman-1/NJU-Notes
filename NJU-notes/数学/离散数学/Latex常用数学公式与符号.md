# LaTeX 常用数学公式与符号总结

LaTeX 数学公式分为**行内公式**（`$...$`）和**独立公式**（`\[...\]`），需使用数学模式。以下是常用符号与结构的速查表。

---

## 1. 希腊字母
| 小写  | 代码         | 大写  | 代码         |
| --- | ---------- | --- | ---------- |
| α   | `\alpha`   | Α   | `A`        |
| β   | `\beta`    | Β   | `B`        |
| γ   | `\gamma`   | Γ   | `\Gamma`   |
| δ   | `\delta`   | Δ   | `\Delta`   |
| ε   | `\epsilon` | Ε   | `E`        |
| ζ   | `\zeta`    | Ζ   | `Z`        |
| η   | `\eta`     | Η   | `H`        |
| θ   | `\theta`   | Θ   | `\Theta`   |
| ι   | `\iota`    | Ι   | `I`        |
| κ   | `\kappa`   | Κ   | `K`        |
| λ   | `\lambda`  | Λ   | `\Lambda`  |
| μ   | `\mu`      | Μ   | `M`        |
| ν   | `\nu`      | Ν   | `N`        |
| ξ   | `\xi`      | Ξ   | `\Xi`      |
| ο   | `o`        | Ο   | `O`        |
| π   | `\pi`      | Π   | `\Pi`      |
| ρ   | `\rho`     | Ρ   | `R`        |
| σ   | `\sigma`   | Σ   | `\Sigma`   |
| τ   | `\tau`     | Τ   | `T`        |
| υ   | `\upsilon` | Υ   | `\Upsilon` |
| φ   | `\phi`     | Φ   | `\Phi`     |
| χ   | `\chi`     | Χ   | `X`        |
| ψ   | `\psi`     | Ψ   | `\Psi`     |
| ω   | `\omega`   | Ω   | `\Omega`   |

---

## 2. 关系运算符
| 符号  | 代码             | 符号  | 代码                |     |
| --- | -------------- | --- | ----------------- | --- |
| ≤   | `\le` 或 `\leq` | ≥   | `\ge` 或 `\geq`    |     |
| ≠   | `\ne` 或 `\neq` | ≈   | `\approx`         |     |
| ≡   | `\equiv`       | ∝   | `\propto`         |     |
| ∼   | `\sim`         | ≅   | `\cong`           |     |
| ⊂   | `\subset`      | ⊆   | `\subseteq`       |     |
| ⊃   | `\supset`      | ⊇   | `\supseteq`       |     |
| ∈   | `\in`          | ∋   | `\ni`             |     |
| ∀   | `\forall`      | ∃   | `\exists`         |     |
| →   | `\to`          | ↔   | `\leftrightarrow` |     |

---

## 3. 算术运算符
| 符号 | 代码 | 符号 | 代码 |
|------|------|------|------|
| + | `+` | − | `-` |
| × | `\times` | ÷ | `\div` |
| ± | `\pm` | ∓ | `\mp` |
| ⋅ | `\cdot` | ∗ | `\ast` |
| ⊕ | `\oplus` | ⊗ | `\otimes` |
| √ | `\sqrt{}` | ∛ | `\sqrt[3]{}` |

---

## 4. 积分、求和、极限
| 符号 | 代码 |
|------|------|
| ∑ | `\sum_{i=1}^{n}` |
| ∫ | `\int_{a}^{b}` |
| ∬ | `\iint` |
| ∮ | `\oint` |
| lim | `\lim_{x \to 0}` |
| ∞ | `\infty` |

---

## 8. 矩阵
```latex
\[
\begin{pmatrix}
a & b \\
c & d
\end{pmatrix}
\]
```
其他环境：`bmatrix`（方括号）、`vmatrix`（竖线）、`pmatrix`（圆括号）。

---


---

## 11. 文本与样式
- 在公式中插入普通文本：`\text{...}`（需 `amsmath`）
- 加粗：`\mathbf{}` 或 `\boldsymbol{}`
- 空格：`\,`（小）、`\:`（中）、`\;`（大）

---

## 12. 常用环境
- 多行公式对齐：`\begin{align} ... \end{align}`
- 分段函数：`\begin{cases} ... \end{cases}`
- 编号公式：`\begin{equation} ... \end{equation}`

---

以下按类别整理群论和图论中常用的 LaTeX 符号代码。

### 一、群论符号

**1. 基本符号**

| 符号 | LaTeX 代码 | 说明 |
|------|-----------|------|
| $\trianglelefteq$ | `\trianglelefteq` | 正规子群（也可用 `\unlhd`） |
| $\trianglerighteq$ | `\trianglerighteq` | 包含正规子群（也可用 `\unrhd`） |
| $\rtimes$ | `\rtimes` | 半直积 |
| $\ltimes$ | `\ltimes` | 左半直积 |
| $\wr$ | `\wr` | 圈积 |
| $\cong$ | `\cong` | 同构 |
| $\simeq$ | `\simeq` | 同构/等价 |
| $\leqslant$ | `\leqslant` | 子群（变体） |
| $\geqslant$ | `\geqslant` | 包含子群（变体） |

**2. 群族字体**

LaTeX 用黑板粗体表示常见群族：

| 符号 | LaTeX 代码 | 含义 |
|------|-----------|------|
| $\mathbb{Z}$ | `\mathbb{Z}` | 整数加群 |
| $\mathbb{Q}$ | `\mathbb{Q}` | 有理数加群 |
| $\mathbb{R}$ | `\mathbb{R}` | 实数加群 |
| $\mathbb{C}$ | `\mathbb{C}` | 复数加群 |
| $\mathbb{Z}_n$ | `\mathbb{Z}_n` | 模 n 剩余类加群 |
| $\mathbb{F}_q$ | `\mathbb{F}_q` | q 元有限域 |

**3. 群作用与轨道**

| 符号 | LaTeX 代码 | 说明 |
|------|-----------|------|
| $\curvearrowright$ | `\curvearrowright` | 群在集合上的右作用 |
| $\curvearrowleft$ | `\curvearrowleft` | 群在集合上的左作用 |
| $\circlearrowright$ | `\circlearrowright` | 作用于自身 |
| $G \backslash X$ | `G \backslash X` | 轨道空间（右作用） |
| $X / G$ | `X / G` | 轨道空间（左作用） |
| $\operatorname{Orb}(x)$ | `\operatorname{Orb}(x)` | x 的轨道 |
| $\operatorname{Stab}(x)$ | `\operatorname{Stab}(x)` | x 的稳定化子 |
| $G_x$ | `G_x` | 稳定化子（简写） |
| $\operatorname{Fix}(g)$ | `\operatorname{Fix}(g)` | g 的不动点集 |

**4. 群构造**

| 符号 | LaTeX 代码 | 说明 |
|------|-----------|------|
| $H \leq G$ | `H \leq G` | H 是 G 的子群 |
| $N \trianglelefteq G$ | `N \trianglelefteq G` | N 是 G 的正规子群 |
| $G/N$ | `G/N` | 商群 |
| $G \times H$ | `G \times H` | 直积 |
| $G \oplus H$ | `G \oplus H` | 直和 |
| $N \rtimes H$ | `N \rtimes H` | 半直积 |
| $\langle S \rangle$ | `\langle S \rangle` | S 生成的子群 |
| $[G, G]$ | `[G, G]` | 换位子群（导群） |
| $Z(G)$ | `Z(G)` | 中心 |
| $C_G(x)$ | `C_G(x)` | 中心化子 |
| $N_G(H)$ | `N_G(H)` | 正规化子 |
| $\operatorname{Aut}(G)$ | `\operatorname{Aut}(G)` | 自同构群 |
| $\operatorname{Inn}(G)$ | `\operatorname{Inn}(G)` | 内自同构群 |
| $\operatorname{Out}(G)$ | `\operatorname{Out}(G)` | 外自同构群 |

**5. 有限群符号**

| 符号 | LaTeX 代码 | 含义 |
|------|-----------|------|
| $S_n$ | `S_n` | n 次对称群 |
| $A_n$ | `A_n` | n 次交错群 |
| $D_n$ | `D_n` | 二面体群（阶 2n） |
| $C_n$ | `C_n` | n 阶循环群 |
| $Q_8$ | `Q_8` | 四元数群 |
| $|G|$ | `|G|` | 群 G 的阶 |
| $[G : H]$ | `[G : H]` | H 在 G 中的指数 |

---

### 二、图论符号

**1. 基本图符号**

| 符号 | LaTeX 代码 | 说明 |
|------|-----------|------|
| $G = (V, E)$ | `G = (V, E)` | 图的定义（顶点集 V，边集 E） |
| $|V(G)|$ | `|V(G)|` | 顶点数（阶） |
| $|E(G)|$ | `|E(G)|` | 边数 |
| $\operatorname{ord}(G)$ | `\operatorname{ord}(G)` | 图的阶 |
| $e(G)$ | `e(G)` | 边数简写 |
| $u \sim v$ | `u \sim v` | u 与 v 相邻 |
| $uv \in E$ | `uv \in E` | 边 uv 属于边集 |
| $N(v)$ | `N(v)` | 顶点 v 的邻域 |
| $N[v]$ | `N[v]` | 闭邻域 |
| $\deg(v)$ | `\deg(v)` | 顶点 v 的度 |
| $\Delta(G)$ | `\Delta(G)` | 最大度 |
| $\delta(G)$ | `\delta(G)` | 最小度 |

**2. 常见图族字体**

通常用黑板粗体或斜体表示特殊图：

```latex
K_n        % 完全图
\overline{K}_n   % 空图（n 个独立点）
P_n        % n 个顶点的路
C_n        % n 个顶点的圈
K_{m,n}    % 完全二部图
W_n        % 轮图（n+1 个顶点）
```

**3. 图参数与不变量**

| 符号                        | LaTeX 代码                  | 说明   |
| ------------------------- | ------------------------- | ---- |
| $\chi(G)$                 | `\chi(G)`                 | 色数   |
| $\chi'(G)$                | `\chi'(G)`                | 边色数  |
| $\omega(G)$               | `\omega(G)`               | 团数   |
| $\alpha(G)$               | `\alpha(G)`               | 独立数  |
| $\kappa(G)$               | `\kappa(G)`               | 点连通度 |
| $\kappa'(G) /\lambda(G)$  | `\kappa'(G)`              | 边连通度 |
| $\tau(G)$                 | `\tau(G)`                 | 点覆盖数 |
| $\nu(G)$                  | `\nu(G)`                  | 匹配数  |
| $\operatorname{diam}(G)$  | `\operatorname{diam}(G)`  | 直径   |
| $\operatorname{girth}(G)$ | `\operatorname{girth}(G)` | 围长   |
| $\operatorname{rad}(G)$   | `\operatorname{rad}(G)`   | 半径   |
| $\operatorname{Aut}(G)$   | `\operatorname{Aut}(G)`   | 自同构群 |

**4. 图运算与关系**

| 符号 | LaTeX 代码 | 说明 |
|------|-----------|------|
| $G \cong H$ | `G \cong H` | 图同构 |
| $G \cup H$ | `G \cup H` | 图的并 |
| $G \cap H$ | `G \cap H` | 图的交 |
| $G \vee H$ | `G \vee H` | 图的联 (join) |
| $G \square H$ | `G \square H` | 笛卡尔积 (Cartesian product) |
| $G \boxtimes H$ | `G \boxtimes H` | 强积 (strong product) |
| $G \times H$ | `G \times H` | 直积 / 张量积 |
| $G - v$ | `G - v` | 删除顶点 v |
| $G - e$ | `G - e` | 删除边 e |
| $G/e$ | `G/e` | 收缩边 e |
| $\overline{G}$ | `\overline{G}` | G 的补图 |
| $G[X]$ | `G[X]` | X 的诱导子图 |

**5. 特殊边集与子图**

| 符号 | LaTeX 代码 | 说明 |
|------|-----------|------|
| $E(S, T)$ | `E(S, T)` | S 与 T 之间的边割 |
| $\partial(S)$ | `\partial(S)` | S 的边边界 |
| $K_n \square K_m$ | `K_n \square K_m` | 需要 `\square`，需 `\usepackage{amssymb}` |
| $\boxtimes$ | `\boxtimes` | 强积符号，需 `\usepackage{amssymb}` |

---

### 三、常用宏包与导言区

建议在导言区加入：

```latex
\usepackage{amsmath, amssymb, amsthm}   % 数学基础
\usepackage{mathtools}                  % 增强数学排版
\usepackage{mathrsfs}                   % \mathscr 花体字体
```


