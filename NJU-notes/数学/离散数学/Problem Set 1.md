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
b)记p为“1+1=2”，q为“2+2=5”，