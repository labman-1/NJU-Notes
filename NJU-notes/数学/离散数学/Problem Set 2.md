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
假设存在一组