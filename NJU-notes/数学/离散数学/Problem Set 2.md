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

# Problem 5
建立命题变元p：天下雨。q：天起雾。r：帆船比赛举行。s：颁发奖杯。t：救生表演如期举行。
则有三个前提：1、$\neg p \lor \neg q \to r \land t$
2、$r\to s$
3、$\neg s$
证明：
$$
\begin{align}
&(1)r\to s\\
&(2)\neg s \to \neg r\\
&(3)\neg s\\
&(4)\neg r\\
&(5)\neg p \lor \neg q \to r \land t\\
&(6)\neg r \lor \neg t \to p\land q\\
&(7)\neg r \lor \neg t\\
&(8)p\land q\\
&(9)p
\end{align}
$$
# Problem 6
建立命题变元p：黑发孩子是男孩。q：金发孩子是女孩。
则这个谜题的前提为$(p\land q)\lor(\neg p\land \neg q)$
$\neg p\lor \neg q$
证明：
$$\begin{align*}
&(1)\neg p\lor \neg q\Rightarrow \neg(p\land q)\\
&(2)
\end{align*}
$$