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
(a)
(b)
(c)
教授看到这一题，露出了“这题我熟，当年我也在这摔过跤”的表情。

“学弟，Problem 5 是离散数学中关于**‘消去律（Cancellation Law）’**的经典探讨。在普通代数里，$a + c = b + c$ 可以推出 $a = b$。但在集合论里，并集和交集都是**‘有损’**的操作，它们会掩盖集合原本的差异。”

这道题的逻辑非常漂亮，(a) 和 (b) 都是用来迷惑你的，(c) 才是真正的重头戏。

---

### 🔍 (a) 若 $A \cup C = B \cup C$，能否断言 $A = B$？

**1. 物理直觉：**
并集操作相当于“合并”。如果 $C$ 是一个非常大的集合，大到把 $A$ 和 $B$ 都“吞”掉了，那么无论 $A$ 和 $B$ 内部长得多么不一样，并出来的结果都只是 $C$。

**2. 判定：不能。**

**3. 满分反例：**
> 令 $C = \{1, 2\}$, $A = \{1\}$, $B = \{2\}$。
> 则 $A \cup C = \{1, 2\}$，$B \cup C = \{1, 2\}$。
> 满足条件 $A \cup C = B \cup C$，但显然 $A \neq B$。

---

### 🔍 (b) 若 $A \cap C = B \cap C$，能否断言 $A = B$？

**1. 物理直觉：**
交集操作相当于“过滤”。如果 $A$ 和 $B$ 在 $C$ 内部的表现是一样的（交集相同），但它们在 $C$ 的**外部**可以有完全不同的元素。

**2. 判定：不能。**

**3. 满分反例：**
> 令 $C = \{1\}$, $A = \{1, 2\}$, $B = \{1, 3\}$。
> 则 $A \cap C = \{1\}$，$B \cap C = \{1\}$。
> 满足条件 $A \cap C = B \cap C$，但显然 $A \neq B$（因为 2 和 3 的存在）。

---

### 🏆 (c) 若 $A \cup C = B \cup C$ 且 $A \cap C = B \cap C$，能否断言 $A = B$？

**1. 物理直觉：**
这就像是一个“双重保险”。第一个条件保证了它们在 $C$ 外部的边界是一致的，第二个条件保证了它们在 $C$ 内部的构成是一致的。两样都占全了，它们只能是一家人。

**2. 判定：能。**（这是集合论中一个非常著名的定理）

**3. 满分证明过程（采用“成员隶属法”，这是南大老师最喜欢的严谨格式）：**

> **证明：**
> 要证 $A = B$，只需证 $A \subseteq B$ 且 $B \subseteq A$。
> 
> 先证 $A \subseteq B$：
> 任意取 $x \in A$。根据 $x$ 是否属于 $C$，分两种情况讨论：
> 1. 若 $x \in C$，则由 $x \in A$ 可知 $x \in A \cap C$。
>    根据已知条件 $A \cap C = B \cap C$，得 $x \in B \cap C$，从而 **$x \in B$**。
> 2. 若 $x \notin C$，则由 $x \in A$ 可知 $x \in A \cup C$。
>    根据已知条件 $A \cup C = B \cup C$，得 $x \in B \cup C$。
>    因为 $x \in B \cup C$ 意味着 $x \in B$ 或 $x \in C$，而已知 $x \notin C$，故必有 **$x \in B$**。
> 综上所述，无论何种情况，若 $x \in A$ 则 $x \in B$，故 **$A \subseteq B$**。
> 
> 同理（利用对称性），可证 **$B \subseteq A$**。
> 
> 因此，$A = B$。证毕。

---

### 🎓 教授的考场小贴士

*   **这道题的 CS 含义**：如果你在写一个 Bug 排查工具。条件 (a) 说明“全集覆盖”不能锁定 Bug，条件 (b) 说明“局部采样”不能锁定 Bug。只有当“覆盖”和“采样”的结果都一致时，两个程序逻辑才是真正等价的。
*   **书写提醒**：证明 (c) 的时候，那个**分情况讨论 ($x \in C$ vs $x \notin C$)** 是得分的关键点。一定要把逻辑分层写清楚。

学弟，这一题拿下后，Problem Set 5 最大的逻辑障碍就扫清了！接下来的题目（比如 Problem 9 的后继）对你来说应该是降维打击了。如果还有不放心的，随时发给我。加油，冲过这个 DDL！🚀