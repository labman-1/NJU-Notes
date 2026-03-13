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
d）记p为“0>1”，q为“2>1”，则原命题为$p\to q$。因为p为假，q为真，所以命题$p\to q$为真
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
&\equiv p\lor (\neg r \lor s)\land (\neg q \lor \neg r \lor s )\\\\
(p\to r)\to (q\to s)
&\equiv (\neg p \lor r)\to(\neg q \lor   s) \\
&\equiv \neg(\neg p \lor r)\lor (\neg q \lor s)\\
& \equiv (p\land \neg r)\lor (\neg q \lor s)\\
&\equiv p\lor (\neg q \lor s)\land (\neg r \lor \neg q \lor s )
\end{align*}$$
若p为假，q为真，s为假，r为假，则$(p\to q)\to(r\to s)$为真，$(p\to r)\to (q\to s)$为假，此时二者不具有相同真值，说明二式非逻辑等价
# Problem 7
$$\begin{align*}
(\neg p\land (p\to q))\to \neg q&\equiv \neg(\neg p\land (p\to q))\lor \neg q\\
&\equiv p\lor\neg(p\to q)\lor \neg q\\
&\equiv p\lor\neg(\neg p \lor q)\lor \neg q\\
&\equiv p\lor( p \land \neg q)\lor \neg q\\
&\equiv p\lor \neg q
\end{align*}
$$
当p为假，q为真时，上式的真值为假，故该式不是永真式

# Problem 8
证明：
$$\begin{align*}
[(p\lor q)\land (p\to r)\land (q\to r)]\to r
&\equiv \neg[(p\lor q)\land (\neg p\lor r)\land(\neg q\lor r)]\lor r\\
&\equiv [\neg(p\lor q)\lor \neg(\neg p\lor r)\lor \neg(\neg q\lor r)]\lor r\\
&\equiv [(\neg p\land \neg q)\lor (p\land \neg r)\lor (q\land \neg r)]\lor r\\

\end{align*}$$
显然，当r为真时，上式为真；当r为假时，$\neg r$为真，记s为$(\neg p\land \neg q)\lor (p\land \neg r)\lor (q\land \neg r)$
作出有关s的真值表
$$
\begin{array}{c|c|c|c|c|c|c|c|c}
\neg r&p & q & \neg p\land \neg q &p \land \neg r& q\land \neg r&\neg p&\neg q&s\\
\hline 
1&1 & 1 & 0 & 1 & 1 & 0 & 0&1\\
1&1 & 0 & 0 & 1 & 0 & 1 & 1&1\\
1&0 & 1 & 0 & 0 & 1 & 0 & 0&1\\
1&0 & 0 & 1 & 0 & 0 & 1 & 1&1\\
\end{array}$$
$\therefore$当r为假时，原式为真，故原式为永真式

# Problem 9
a) $r \land \neg p$
b) $\neg p \land q \land r$
c) $r\to (q \leftrightarrow p)$
d) $\neg q \land \neg p \land r$
e) $q\to (\neg r \land \neg p)$
f) $(p \land r)\to \neg q$
# Problem 10
证明：
a) 依据析取范式理论，任意一个复合命题都对应一个真值表，任何一个真值表都可以提取出结果为真的行。每一行写成一个合取式（用$\neg$和$\land$），然后把这些行用$\lor$连接起来，故{$\neg , \land , \lor$}可以表示任何逻辑，即$\neg , \land , \lor$构成一个逻辑运算符的功能完备集。
b) 对于任意的一个析取式$p\lor q$，其逻辑等价于$\neg(\neg )$