
### 第一步：环境准备（1分钟搞定）

不要在本地折腾繁琐的 TeX Live 环境。
*   **推荐使用：[Overleaf](https://www.overleaf.com/)**（在线版 Google Docs 版的 LaTeX）。
*   注册即用，自带各种宏包，无需安装，支持实时预览。

---

### 第二步：一个标准的作业模板

你可以直接把这段代码复制到 Overleaf 的 `main.tex` 里。它包含了 NJU 同学写作业最常用的配置。

```latex
\documentclass[12pt, a4paper]{article}

% --- 必备宏包 ---
\usepackage[UTF8]{ctex}     % 支持中文
\usepackage{amsmath, amssymb, amsthm} % 数学全家桶
\usepackage{geometry}       % 调整页边距
\usepackage{enumerate}      % 自动编号
\usepackage{graphicx}       % 插入图片
\usepackage{fancyhdr}       % 设置页眉页脚
\usepackage{xcolor}         % 颜色支持

\geometry{left=2.5cm,right=2.5cm,top=2.5cm,bottom=2.5cm}

% --- 标题信息 ---
\title{离散数学与 DLCO 作业}
\author{南京大学-工试班-学号-姓名}
\date{\today}

\begin{document}
\maketitle

\section*{Problem 1: 逻辑证明}
% 这里开始写正文
已知前提 $P \rightarrow Q$ 和 $P$，证明 $Q$。
\begin{proof}
    使用肯定前件律 (Modus Ponens)：
    \begin{equation}
        (P \land (P \rightarrow Q)) \Rightarrow Q
    \end{equation}
    因此结论成立。
\end{proof}

\end{document}
```

---

### 第三步：快速上手 Cheat Sheet

#### 1. 数学符号（离散数学/计组最常用）
LaTeX 的数学模式需要写在 `$ ... $`（行内）或 `$$ ... $$`（行间居中）里。

| 类别 | LaTeX 代码 | 显示效果 |
| :--- | :--- | :--- |
| **逻辑** | `\neg P, P \land Q, P \lor Q` | $\neg P, P \land Q, P \lor Q$ |
| **蕴含/等价** | `\to, \Rightarrow, \leftrightarrow, \equiv` | $\to, \Rightarrow, \leftrightarrow, \equiv$ |
| **量词** | `\forall x, \exists y` | $\forall x, \exists y$ |
| **集合** | `\in, \notin, \subseteq, \cup, \cap` | $\in, \notin, \subseteq, \cup, \cap$ |
| **数集** | `\mathbb{R}, \mathbb{Z}, \mathbb{N}, \mathbb{Q}` | $\mathbb{R}, \mathbb{Z}, \mathbb{N}, \mathbb{Q}$ |
| **DLCO 取反** | `\overline{A \cdot B}` | $\overline{A \cdot B}$ |
| **下标与上标** | `x_i, 2^n` | $x_i, 2^n$ |
| **分式/根号** | `\frac{a}{b}, \sqrt{x}` | $\frac{a}{b}, \sqrt{x}$ |

#### 2. DLCO 特有：真值表与卡诺图
写 DLCO 作业，**表格**是避不开的。

**真值表模板（使用 `tabular`）：**
```latex
\begin{table}[h]
    \centering
    \begin{tabular}{|c|c|c|} \hline
        $A$ & $B$ & $F = A \cdot B$ \\ \hline
        0 & 0 & 0 \\
        0 & 1 & 0 \\
        1 & 0 & 0 \\
        1 & 1 & 1 \\ \hline
    \end{tabular}
\end{table}
```

**卡诺图（进阶）：**
计组作业经常要画卡诺图。学姐建议你搜索并使用 `karnaugh-map` 这个宏包，或者**直接在电脑上画好截图用 `\includegraphics` 插入**（这是最省时间的办法）。

---

### 第四步：格式微调技巧

1.  **多行对齐（推导公式）：**
    使用 `align*` 环境，在需要对齐的 `=` 前面加 `&`。
    ```latex
    \begin{align*}
        \overline{A \lor (B \land C)} &= \overline{A} \land \overline{(B \land C)} \quad \text{(De Morgan)} \\
        &= \overline{A} \land (\overline{B} \lor \overline{C})
    \end{align*}
    ```

2.  **分条列项：**
    ```latex
    \begin{enumerate}[1.]
        \item 第一步：...
        \item 第二步：...
    \end{enumerate}
    ```

---

### 第五步：学姐的私藏利器（快速通关秘籍）

对于转专业选手，时间就是绩点！推荐三个提升效率的工具：

1.  **[Mathpix Snip](https://mathpix.com/)（神中神）：**
    你手写一段公式，拍照或截图，它能自动识别并转成 LaTeX 代码。写作业的速度提升 10 倍！
2.  **[Detexify](https://detexify.kirelabs.org/classify.html)：**
    不知道某个奇怪符号的代码？在上面画一下，它会告诉你。
3.  **[Tables Generator](https://www.tablesgenerator.com/)：**
    LaTeX 里的表格代码很难写。在网页上像操作 Excel 一样填好，点击 Generate 就能生成代码。
