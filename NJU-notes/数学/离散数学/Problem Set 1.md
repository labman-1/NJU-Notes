# Problem 1
表一：$$\neg(p\lor q)\equiv\neg p\land \neg q $$
$$
\begin{array}{c|c|c|c|c|c|c}
p & q & p\lor q &\neg (p\lor q)&\neg p&\neg q&\neg p\land\neg q\\
\hline 
1 & 1 & 1 & 0 & 0 & 0 & 0\\
1 & 0 & 1 & 0 & 0 & 1 & 0\\
0 & 1 & 1 & 0 & 1 & 0 & 0\\
0 & 0 & 0 & 1 & 1 & 1 & 1\\
\end{array}$$

表二：$$\neg(p\land q)\equiv\neg p\lor \neg q $$

$$
\begin{array}{c|c|c|c|c|c|c}
p & q & p\land q &\neg (p\land q)&\neg p&\neg q&\neg p\lor\neg q\\
\hline 
1 & 1 & 1 & 0 & 0 & 0 & 0\\
1 & 0 & 0 & 1 & 0 & 1 & 1\\
0 & 1 & 0 & 1 & 1 & 0 & 1\\
0 & 0 & 0 & 1 & 1 & 1 & 1\\
\end{array}$$
# Problem 2
a)记p为“2+2=5”，q为“1+1=3“，则原命题为$p\leftrightarrow q$。因为p为假，所以命题 $p\to q$为真；因为q为假，所以命题$q\to p$为真，所以$p\leftrightarrow q$为真
b)记p为“1+1=2”，q为“2+2=5”，则原命题为$p\to q$。因为p为真，q为假，所以命题$p\to q$为假
c）记p为“1+1=3”，q为“2+2=5”，则原命题为$p\to q$。因为p为假，q为假，所以命题$p\to q$为真
d）记p为“0>1”，q为“2>1”，则原命题为$p\to q$。因为p为假，q为假，所以命题$p\to q$为真
# Problem 3
$g\to (r\land \neg m \land \neg b)$
# Problem 4
证明：$\because q\to r \equiv \neg q \lor r$ 
$\therefore \neg p\to (q\to r)\equiv \neg p\to(\neg q \lor r)$
$\therefore \neg p\to (q\to r)\equiv p \lor (\neg q \lor r)$
又$\because q\to (p\lor r)\equiv \neg q \lor(p\lor r)$
$\therefore \neg p\to (q\to r)\equiv q\to (p\lor r)$
# Problem 5
证明：$\because q\to r \equiv \neg q \lor r$ 
$\therefore p\to (q\to r)\equiv p\to(\neg q \lor r)$
$\therefore p\to (q\to r)\equiv \neg p \lor (\neg q \lor r)$
$$\begin{align*}
\therefore p\land q \to r 
&\equiv \neg(p\land q) \lor r\\
&\equiv \neg p \lor \neg q \lor r\\
&\equiv p \to(q\to r)
\end{align*}
$$
# Problem 6
$$\begin{align*}
\because (p\to q)\to(r\to s)
&\equiv (\neg p \lor q)\to(\neg r \lor   s) \\
&\equiv \neg(\neg p \lor q)\lor (\neg r \lor s)\\
& \equiv (p\land \neg q)\lor (\neg r \lor s)\\
(p\to r)\to (q\to s)
&\equiv (\neg p \lor r)\to(\neg q \lor   s) \\
&\equiv \neg(\neg p \lor r)\lor (\neg q \lor s)\\
& \equiv (p\land \neg r)\lor (\neg q \lor s)\\
\end{align*}$$
