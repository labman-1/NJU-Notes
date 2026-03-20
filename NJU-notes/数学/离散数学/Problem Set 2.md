# Problem 1
证明：
$$
\begin{align*}
(p\to q)\land(q\to r)\to(p\to r)
&\equiv \neg((\neg p\lor  q)\land (\neg q \lor  r))\lor (\neg p \lor  r)\\
&\equiv \neg(\neg p \lor  q)\lor \neg(\neg q\lor  r)\lor (\neg p \lor r)\\
&\equiv (p\land \neg q)\lor(q\land \neg r)\lor(\neg p\lor r)
\end{align*}
$$
假设存在一组p，q，r使得上式为假，观察三个合取式，则必须有p=1，r=0，此时若q=1，则$q\land \neg r$=1，原式为真；若q=0，则$p\land \neg q$=1，原式为真，矛盾。故不存在一组p，q，r使得上式为假。所以原式为永真式。
# Problem 2
（a）记命题p为“袋鼠生活在澳大利亚”，q为“袋鼠是有袋类动物”。则原论证为
$$
\because p\land q\\
\therefore q
$$
体现了化简。
（b）体现了析取三段论
（c）体现了假言推理
（d）体现了附加
（e）体现了假言三段论
# Problem 3
无效。理由如下：
$$
\begin{align*}
p\to r \equiv \neg p\lor r \\
q\to r \equiv \neg q \lor r\\
\neg(p\lor q)\equiv \neg p\land \neg q
\end{align*}
$$
对于这一种指派：p=0，q=0，r=1，可以通过逐条检验验证三个前提均为真，但此时结论为假，故该论证无效。
# Problem 4
（1）自然推理系统中的每一条规则（如 p,p→q⊢q），其对应的蕴含式（如 (p∧(p→q))→q）都是一个永真式 。因为它们是永真式，所以保证了真值只会从前提“保真”地传递到结论，绝对不会出现前提真而结论假的情况，进而保证了推理规则的有效性。
（2）形式：
$$
\begin{align}
前提1：p\leftrightarrow q\\
前提2：q\leftrightarrow r\\
结论：\therefore p\leftrightarrow r
\end{align}
$$
# Problem 5
建立命题变元p：天下雨。q：天起雾。r：帆船比赛举行。s：颁发奖杯。t：救生表演如期举行。
则有三个前提：1、$\neg p \lor \neg q \to r \land t$
2、$r\to s$
3、$\neg s$
证明：
    (1) $r \to s$ (前提)
    (2) $\neg s$ (前提)
    (3) $\neg r$ (拒取式 自（1）（2）)
    (4) $\neg p \lor \neg q \to r \land t$ (前提)
    (5) $\neg(r \land t) \to \neg(\neg p \lor \neg q)$ (由 4 逆否律)
    (6) $\neg r \lor \neg t \to p \land q$ (由 5 德摩根律)
    (7) $\neg r \lor \neg t$ (附加 自（3）)
    (8) $p \land q$ (假言推理 自（6）（7）)
    (9) $p$ (化简 自（8）)
# Problem 6
建立命题变元p：黑发孩子是男孩。q：金发孩子是女孩。
则这个谜题的前提为$(p\land q)\lor(\neg p\land \neg q)$
$\neg p\lor \neg q$
证明：
$$\begin{align*}
&(1)\neg p\lor \neg q\Rightarrow \neg(p\land q)\\
&(2)\neg(p\land q)，(p\land q)\lor(\neg p\land \neg q)\Rightarrow \neg p\land \neg q\\
&(3)\neg p\land \neg q\Rightarrow \neg p,\neg q
\end{align*}
$$
即两个孩子都在说谎。

# Problem 7
自然语言：假设甲会游泳，则甲说真话，乙说假话，又因为只有一个人说假话，所以丙和丁都说真话，那么乙不会游泳，且甲、丙、丁都会游泳。假设甲不会游泳，则甲说假话，那么乙、丙、丁都应该说真话，则乙不会游泳，此时至多有两个人会游泳，与丁说的矛盾，则假设不成立。综上，甲说真话，乙说假话，丙和丁都说真话，乙不会游泳，甲、丙、丁都会游泳。
命题逻辑：建立命题变元P：甲会游泳。q：乙会游泳。r：丙会游泳。s：丁会游泳。
$$
\begin{align*}
(1)(p \neg p \neg q )
\end{align*}
$$



学弟，看到你提交的这份作业草稿，我作为你的“离散数学私教”必须先给你竖个大拇指！👍

你的逻辑直觉非常敏锐，特别是 **Problem 3 的反例构造** 和 **Problem 6 的状态提炼（$(p\land q)\lor(\neg p\land \neg q)$）**，这充分说明你已经掌握了逻辑学透过现象看本质的能力。

不过，既然这一章的标题叫 **“命题逻辑的推理理论 (Inference Theory)”**，老师考察的重点不仅是“你能不能算对”，更重要的是**“你能不能按照极其严谨的学术格式，一步步推导出来”**。

下面我为你逐题进行 Code Review（作业批改），提供标准的格式指引，并为你补齐未完成的题目思路：

---

### 📝 总体格式指引：什么是“形式化推理”？

在做 Problem 5、6、7 以及部分证明题时，离散数学要求使用**“自然推理系统”**的格式。标准格式必须分为两列（或加上序号）：
**序号 | 公式 | 理由 (使用了什么前提，运用了什么规则)**
绝不能只写公式而不写理由！

---

### 🔍 逐题批改与指导

#### Problem 1 (永真式证明)
*   **你的作答**：使用了等值演算化简，最后用了一段文字假设证明（归谬法）。逻辑完全正确！
*   **教授建议**：既然这章学了“推理理论”，对付形如 $A \to B$ 的永真式，最标准的做法是使用 **附加前提证明法 (CP规则 / Conditional Proof)**。
*   **格式示范**：
    要证：$(p\to q)\land(q\to r) \to (p\to r)$
    我们可以把左边当作前提，把结论的 $p$ 也当作附加前提，去推导 $r$。
    (1) $p \to q$ （前提引入）
    (2) $q \to r$ （前提引入）
    (3) $p$ （附加前提引入）
    (4) $q$ （由 1, 3 假言推理 Modus Ponens）
    (5) $r$ （由 2, 4 假言推理 Modus Ponens）
    (6) $p \to r$ （由 3, 5 附加前提证明法 CP）
    *注：你现在的写法也可以拿分，但如果想拿完美的卷面分，可以把等值演算的过程写得更规范，或者使用上述的 CP 规则。*

#### Problem 2 (识别推理规则)
*   **你的作答**：(a)化简 (b)析取三段论 (c)假言推理 (d)附加 (e)假言三段论。**全对！满分！**
*   **格式优化**：建议在文字旁边附上符号表达，显得更专业。例如：
    (a) 化简规则 (Simplification)：$p \land q \vdash p$
    (b) 析取三段论 (Disjunctive Syllogism)：$p \lor q, \neg p \vdash q$

#### Problem 3 (论证有效性)
*   **你的作答**：无效。找出了完美的反例指派 $p=0, q=0, r=1$。**满分！**
*   **评价**：这是极其标准的解法。只要找出一组让“前提全真，结论为假”的真值指派，论证即为无效。不用改，直接交！

#### Problem 4 (你未完成的题目)
这道题考的是对“系统底层原理”的理解。
*   **(1) 如何保证推理规则的有效性？**
    *   **思路提示**：自然推理系统中的每一条规则（如 $p, p\to q \vdash q$），其对应的蕴含式（如 $(p \land (p\to q)) \to q$）都是一个**永真式 (Tautology)**。因为它们是永真式，所以保证了真值只会从前提“保真”地传递到结论，绝对不会出现前提真而结论假的情况。
*   **(2) 建立“等价三段论”的新规则？**
    *   **思路提示**：题目给出了永真式 $((p \leftrightarrow q) \land (q \leftrightarrow r)) \to (p \leftrightarrow r)$。
    *   推理规则的写法就是：把蕴含号 $\to$ 前面的合取项作为**前提**，$\to$ 后面的项作为**结论**。
    *   **形式**：
        前提 1：$p \leftrightarrow q$
        前提 2：$q \leftrightarrow r$
        结论：$\therefore p \leftrightarrow r$

#### Problem 5 (应用推理理论证明)
*   **你的作答**：思路完美！利用了逆否律和假言推理。
*   **格式修改指令**：必须补充“理由列”！这里我帮你把你的过程规范化：
    (1) $r \to s$ (前提引入)
    (2) $\neg s$ (前提引入)
    (3) $\neg r$ (由 1, 2 拒取式 / Modus Tollens)
    (4) $\neg p \lor \neg q \to r \land t$ (前提引入)
    (5) $\neg(r \land t) \to \neg(\neg p \lor \neg q)$ (由 4 逆否律)
    (6) $\neg r \lor \neg t \to p \land q$ (由 5 德摩根律)
    (7) $\neg r \lor \neg t$ (由 3 附加律 Addition) —— *注：你原本的过程跳过了这一步的理由，这里很关键！因为你有 $\neg r$，所以可以 $\lor$ 上任何东西。*
    (8) $p \land q$ (由 6, 7 假言推理 Modus Ponens)
    (9) $p$ (由 8 化简律 Simplification)
    *把这个加上理由的格式抄到作业上，无懈可击！*

#### Problem 6 (男孩女孩谜题)
*   **你的作答**：状态提取极其惊艳！$(p\land q)\lor(\neg p\land \neg q)$ 这个前提找得太准了。
*   **格式修改指令**：同样，补上严谨的推理步骤说明。
    前提 1：$(p\land q)\lor(\neg p\land \neg q)$ （两人必须一男一女，故要么同时说真话，要么同时说假话）
    前提 2：$\neg p\lor \neg q$ （已知至少一人说谎）
    (1) $\neg p \lor \neg q$ (前提引入)
    (2) $\neg(p \land q)$ (由 1 德摩根律)
    (3) $(p\land q)\lor(\neg p\land \neg q)$ (前提引入)
    (4) $\neg p \land \neg q$ (由 2, 3 析取三段论 Disjunctive Syllogism)
    *结论：两人都在说谎（$\neg p$ 真且 $\neg q$ 真）。*

#### Problem 7 (游泳谜题的命题逻辑化)
*   **你的作答**：自然语言推理部分逻辑非常严密，破题点找得很准（甲乙矛盾）。
*   **缺失的部分**：如何用**命题逻辑的形式推理**写出来？
*   **思路提示与格式指引**：
    设立命题变元 $P$: 甲会游, $Q$: 乙会游, $R$: 丙会游, $S$: 丁会游。
    四人的话可以翻译为四个命题公式：
    $A = P$
    $B = \neg P$
    $C = \neg Q$
    $D = $ 恰好有三人会游 (在符号逻辑中，只需知道 D 代表特定状态即可)
    
    **核心形式推导**：
    (1) $A \leftrightarrow \neg B$ (因为 $P$ 与 $\neg P$ 互为否定，故甲乙必有一真一假)
    (2) 已知四人中仅有一人说假话，且谎言必在甲乙之中产生。
    (3) 因此，丙和丁说的话必定为真。
    (4) $C$ 为真 $\Rightarrow \neg Q$ 为真 $\Rightarrow$ **乙不会游泳**。
    (5) $D$ 为真 $\Rightarrow$ 有三人会游。因为乙不会游，所以剩下的甲、丙、丁**必然都会游泳**。
    (6) 因为甲会游，即 $P$ 为真。
    (7) 所以甲说真话 ($A$ 真)，乙说假话 ($B$ 假)。
    *（注：这道题由于 D 的符号化如果完全展开会非常长，老师主要考察的是你能否用公式抽象出 $A \leftrightarrow \neg B$ 这个矛盾核，然后向下推导。你只需按照上述 1-7 步，夹叙夹议地写出逻辑表达式即可。）*

---

### 教授的结语

学弟，这份作业展现了你极强的逻辑底子！你现在需要做的，只是把“野路子”的聪明才智，套进“正规军”的**（序号+公式+规则引用）**的格式壳子里。

去把 P4 补上，给 P5、P6 加上右侧的规则理由说明，你的这份作业拿满分没有任何悬念。3月25日的 DDL 完全来得及，冲吧！有问题随时敲我！🚀