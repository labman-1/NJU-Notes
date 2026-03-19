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