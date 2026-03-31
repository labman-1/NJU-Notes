# LaTeX 常用数学公式与符号总结

LaTeX 数学公式分为**行内公式**（`$...$`）和**独立公式**（`\[...\]`），需使用数学模式。以下是常用符号与结构的速查表。

---

## 1. 希腊字母
| 小写 | 代码 | 大写 | 代码 |
|------|------|------|------|
| α | `\alpha` | Α | `A` |
| β | `\beta` | Β | `B` |
| γ | `\gamma` | Γ | `\Gamma` |
| δ | `\delta` | Δ | `\Delta` |
| ε | `\epsilon` | Ε | `E` |
| ζ | `\zeta` | Ζ | `Z` |
| η | `\eta` | Η | `H` |
| θ | `\theta` | Θ | `\Theta` |
| ι | `\iota` | Ι | `I` |
| κ | `\kappa` | Κ | `K` |
| λ | `\lambda` | Λ | `\Lambda` |
| μ | `\mu` | Μ | `M` |
| ν | `\nu` | Ν | `N` |
| ξ | `\xi` | Ξ | `\Xi` |
| ο | `o` | Ο | `O` |
| π | `\pi` | Π | `\Pi` |
| ρ | `\rho` | Ρ | `R` |
| σ | `\sigma` | Σ | `\Sigma` |
| τ | `\tau` | Τ | `T` |
| υ | `\upsilon` | Υ | `\Upsilon` |
| φ | `\phi` | Φ | `\Phi` |
| χ | `\chi` | Χ | `X` |
| ψ | `\psi` | Ψ | `\Psi` |
| ω | `\omega` | Ω | `\Omega` |

---

## 2. 关系运算符
| 符号 | 代码 | 符号 | 代码 |
|------|------|------|------|
| ≤ | `\le` 或 `\leq` | ≥ | `\ge` 或 `\geq` |
| ≠ | `\ne` 或 `\neq` | ≈ | `\approx` |
| ≡ | `\equiv` | ∝ | `\propto` |
| ∼ | `\sim` | ≅ | `\cong` |
| ⊂ | `\subset` | ⊆ | `\subseteq` |
| ⊃ | `\supset` | ⊇ | `\supseteq` |
| ∈ | `\in` | ∋ | `\ni` |
| ∀ | `\forall` | ∃ | `\exists` |
| → | `\to` | ↔ | `\leftrightarrow` |

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

## 5. 括号与分隔符
| 符号 | 代码 |
|------|------|
| ( ) | `( )` |
| [ ] | `[ ]` |
| { } | `\{ \}` |
| 自适应 | `\left( \right)` |
| 大括号 | `\begin{cases} ... \end{cases}` |

---

## 6. 分数与根式
| 符号 | 代码 |
|------|------|
| 分数 | `\frac{分子}{分母}` |
| 根式 | `\sqrt{表达式}` |
| n次根 | `\sqrt[n]{表达式}` |

---

## 7. 上下标
| 效果 | 代码 |
|------|------|
| x² | `x^{2}` |
| xᵢ | `x_{i}` |
| x_{ij} | `x_{ij}` |
| e^{i\pi} | `e^{i\pi}` |

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

## 9. 函数名
| 标准函数 | 代码 |
|----------|------|
| sin, cos | `\sin`, `\cos` |
| log, ln | `\log`, `\ln` |
| max, min | `\max`, `\min` |
| arg | `\arg` |
| det | `\det` |

---

## 10. 箭头
| 符号 | 代码 | 符号 | 代码 |
|------|------|------|------|
| ← | `\leftarrow` | → | `\rightarrow` |
| ⇐ | `\Leftarrow` | ⇒ | `\Rightarrow` |
| ↔ | `\leftrightarrow` | ⇔ | `\Leftrightarrow` |
| ↑ | `\uparrow` | ↓ | `\downarrow` |

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

以上是 LaTeX 数学模式中最常用的符号与结构。更多细节可查阅 `amsmath` 宏包文档。