# Problem 1
(a) 真
(b)真
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

