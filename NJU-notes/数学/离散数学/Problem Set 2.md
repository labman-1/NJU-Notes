作为一名深谙中西方哲学思想，见证了三次工业革命，在当代拥有丰富代码经验、深度使用了ai的资深工程师的角度，讲讲在现代ai高速发展的阶段，学习算法与数据结构除了应对我的转专业考试、竞赛、oj等硬性要求之外，是否还有实际意义？作为你的学弟，我看到现在有人号称文科生也可以指挥一支“ai军队”进军github贡献者名单，有蓝领工人真正解决了自己每天面临的行业痛点，有公司大量裁撤前端、倒逼后端工程师转全栈开发。工具本应是解放人类的，但是似乎ai时代下，失去的工作岗位远大于它创造的工作岗位，同时软件工程师们必须指挥ai干以往数倍的工作，拿着更低的薪水。虽然我已经无法回头了，但是现在转cs真的还有前途吗？# Problem 1
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
    (1) $\neg p \lor \neg q$ (前提)
    (2) $\neg(p \land q)$ (由 1 德摩根律)
    (3) $(p\land q)\lor(\neg p\land \neg q)$ (前提)
    (4) $\neg p \land \neg q$ (由 2, 3 析取三段论 )
    *结论：两人都在说谎（$\neg p$ 真且 $\neg q$ 真）。

# Problem 7
自然语言：假设甲会游泳，则甲说真话，乙说假话，又因为只有一个人说假话，所以丙和丁都说真话，那么乙不会游泳，且甲、丙、丁都会游泳。假设甲不会游泳，则甲说假话，那么乙、丙、丁都应该说真话，则乙不会游泳，此时至多有两个人会游泳，与丁说的矛盾，则假设不成立。综上，甲说真话，乙说假话，丙和丁都说真话，乙不会游泳，甲、丙、丁都会游泳。
命题逻辑：建立命题变元P：甲会游泳。q：乙会游泳。r：丙会游泳。s：丁会游泳。
四个人的话可以翻译为四个命题公式：
A=p
B=$\neg p$
C=$\neg q$
D=恰好有三人会游
    (1) $A \leftrightarrow \neg B$ (因为 $P$ 与 $\neg P$ 互为否定，故甲乙必有一真一假)
    (2) 已知四人中仅有一人说假话，则谎言必在甲乙之中产生。
    (3) 因此，丙和丁说的话必定为真。
    (4) $C$ 为真 $\Rightarrow \neg Q$ 为真 $\Rightarrow$ 乙不会游泳。
    (5) $D$ 为真 $\Rightarrow$ 有三人会游。因为乙不会游，所以剩下的甲、丙、丁必然都会游泳。
    (6) 因为甲会游，即 $P$ 为真。
    (7) 所以甲说真话 ($A$ 真)，乙说假话 ($B$ 假)。