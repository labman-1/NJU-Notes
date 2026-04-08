# Problem 1
(a) 真
(b)假
(c)假
(d)假
(e)真
(f)假
# Problem 2
(a)否
(b)是
(c)否
(d)是
# Problem 3
(a){-1,0,1}
(b)$\mathbb{Z}-\{0,1\}$
(c)$\emptyset$
# Problem 4
a)令A={1}，C={1}，B={1}，则左式=$\emptyset\neq C$，原式不成立
b)$左式=A\cap\overline{(B\cap \overline C)}=A\cap(\overline B\cup C)=(A\cap\overline B)\cup(A\cap C)$
$$\begin{align*}
右式&=(A\cap \overline B)\cap\overline{(A\cap \overline C)}\\
&=(A\cap \overline B)\cap(\overline A\cup C)\\
&=(A\cap\overline B\cap \overline A)\cup(A\cap\overline B\cap C)\\
&=A\cap\overline B\cap C
\end{align*}
$$
左边有 (A−B) 这么大一块，右边却要求必须还在 C 里面。显然左边比右边大得多。所以这个等式**也不成立**。
# Problem 5
(a)令 $C = \{1, 2\}$, $A = \{1\}$, $B = \{2\}$。
 则 $A \cup C = \{1, 2\}$，$B \cup C = \{1, 2\}$。
 满足条件 $A \cup C = B \cup C$，但显然 $A \neq B$。
(b) 令 $C = \{1\}$, $A = \{1, 2\}$, $B = \{1, 3\}$。
 则 $A \cap C = \{1\}$，$B \cap C = \{1\}$。
 满足条件 $A \cap C = B \cap C$，但显然 $A \neq B$（因为 2 和 3 的存在）。
(c) **证明：**
要证 $A = B$，只需证 $A \subseteq B$ 且 $B \subseteq A$。
先证 $A \subseteq B$：
任意取 $x \in A$。根据 $x$ 是否属于 $C$，分两种情况讨论：
1. 若 $x \in C$，则由 $x \in A$ 可知 $x \in A \cap C$。
   根据已知条件 $A \cap C = B \cap C$，得 $x \in B \cap C$，从而 **$x \in B$**。
2. 若 $x \notin C$，则由 $x \in A$ 可知 $x \in A \cup C$。
   根据已知条件 $A \cup C = B \cup C$，得 $x \in B \cup C$。
因为 $x \in B \cup C$ 意味着 $x \in B$ 或 $x \in C$，而已知 $x \notin C$，故必有 **$x \in B$**。
综上所述，无论何种情况，若 $x \in A$ 则 $x \in B$，故 **$A \subseteq B$**。
 
同理（利用对称性），可证 **$B \subseteq A$**。 
因此，$A = B$。证毕。
# Problem 6

**1. 证明必要性 ($\implies$)：**
*   **假设**：$A \subseteq B$。
*   **证明**：
    设任意元素 $x \in \bar{B}$。
    根据补集定义，可知 $x \in U$ 且 **$x \notin B$**。
    由于已知 $A \subseteq B$，根据包含关系的定义（若在 $A$ 中必在 $B$ 中），其**逆否逻辑**为：若不在 $B$ 中，则必不在 $A$ 中。
    既然 $x \notin B$，那么必然有 **$x \notin A$**。
    根据补集定义，可知 $x \in \bar{A}$。
    故 $\bar{B} \subseteq \bar{A}$ 成立。

**2. 证明充分性 ($\impliedby$)：**
*   **同理**：设 $x \in A$，则 $x \notin \bar{A}$。因为 $\bar{B} \subseteq \bar{A}$，若 $x$ 不在 $\bar{A}$ 中，则必不在 $\bar{B}$ 中（逆否）。由于 $x \notin \bar{B}$，得 $x \in B$。
*   **结论**：双向成立，原命题得证。

# Problem 7
#### (a) 证明 $A \oplus A = \emptyset$
$A \oplus A = (A - A) \cup (A - A)$
因为 $A - A = \emptyset$，所以 $原式=\emptyset \cup \emptyset = \emptyset$。
#### (b) 证明 $A \oplus U = \bar{A}$
$A \oplus U = (A - U) \cup (U - A)$

1. 因为 $A \subseteq U$，所以 $A$ 里面没有任何元素不在 $U$ 里，即 $A - U = \emptyset$。
2. $U - A$ 根据定义就是 $\bar{A}$（绝对补集）。
3. $\therefore A \oplus U=\emptyset \cup \bar{A} = \bar{A}$。

#### (c) 证明 $(A \oplus B) \oplus B = A$
看元素 $x$ 对 $A$ 和 $B$ 的所属情况（1代表属于，0代表不属于）：

| $x \in A$ | $x \in B$ | $x \in A \oplus B$ | $x \in (A \oplus B) \oplus B$ |     |
| :-------- | :-------- | :----------------- | :---------------------------- | --- |
| 0         | 0         | 0                  | **0**                         |     |
| 0         | 1         | 1                  | **0**                         |     |
| 1         | 0         | 1                  | **1**                         |     |
| 1         | 1         | 0                  | **1**                         |     |

注意到最后一列的结果和第一列 $x \in A$的结果相同
$\therefore$根据外延公理，这两个集合相等。
# Problem 8

#### (a) 求 $\bigcup_{i=1}^n A_i$
$\bigcup_{i=1}^n A_i=A_n=\{ x \in \mathbb{Z} \mid x \le n \}$

#### (b) 求 $\bigcap_{i=1}^n A_i$
因为 $A_1$ 是这串序列里最小的，且它被包含在所有的 $A_i$ 中，所以它就是公共部分。
$\bigcap_{i=1}^n A_i=A_1=\{ x \in \mathbb{Z} \mid x \le 1 \}$ 

# Problem 9
#### (a) $\{1, 2, 3\}$ 之后继
$\{1, 2, 3, \{1, 2, 3\}\}$

#### (b) $\emptyset$ 之后继
$\emptyset^+ = \emptyset \cup \{\emptyset\}=\{\emptyset\}$

#### (c) $\{\emptyset\}$ 之后继
  $\emptyset^+ = \{\emptyset\} \cup \{\{\emptyset\}\}=\{\emptyset, \{\emptyset\}\}$
#### (d) $\{\emptyset, \{\emptyset\}\}$ 之后继
$\emptyset^+ = \{\emptyset, \{\emptyset\}\} \cup \{\{\emptyset, \{\emptyset\}\}\}=\{\emptyset, \{\emptyset\}, \{\emptyset, \{\emptyset\}\}\}$
# Problem 10
证明：
1.  左 $\subseteq$ 右：
    设任意 $x \in A \cup B \cup C$。
    *   若 $x$ 属于且仅属于其中一个集合（比如仅属于 A），则 $x \in A-B$，属于右边第一项。
    *   若 $x$ 同时属于两个集合（比如 $x \in A \cap B$ 但 $x \notin C$），则 $x \in B-C$（因为 $x$ 在 B 但不在 C），属于右边第二项。
    *   若 $x$ 同时属于三个集合，则 $x \in A \cap B \cap C$，属于右边第四项。
    *   结论：所有情况都在右边。

2.  右 $\subseteq$ 左：
    由于 (A−B),(B−C),(C−A),(A∩B∩C)分别都是 A,B,C 的子集，它们的并集自然包含A∪B∪C 中。得证
