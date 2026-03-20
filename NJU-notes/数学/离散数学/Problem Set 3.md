# Problem 1
(a)$\exists x \,(C(x)\land D(x)\land F(x))$
(b)$\forall x\,( C(x)\lor D(x)\lor F(x))$
(c)$\exists x\, (C(x)\land F(x)\land \neg D(x))$
(d)$\forall x\, (\neg C(x)\lor\neg D(x)\lor \neg F(x))$
(e)$(\exists x\, C(x))\land(\exists x\, D(x))\land(\exists x\, F(x))$
# Problem 2
（a）当x=$\sqrt{2}$时，$x^2=2$，则原命题为真
（b）$\because \forall x(x^2>=0)$
$\therefore \forall x(x^2\ne-1)$
即原命题为假
（c）$\because \forall x(x^2+2>=2)$
$\therefore \forall x(x^2+2>=1)$
即原命题为真
（d）当x=1时，$x^2=x$，则原命题为假。
# Problem 3
（a）$\because \exists! xP(x)$
$\therefore \exists x_0 P(x_0),即\exists x P(x)$
则原命题为真
（b）$\because \forall xP(x)$
$\therefore \exists x_0,x_1\, P(x_0),P(x_1)$
则$\exists! xP(x)$为假，原命题为假
（c）$\because \neg \forall xP(x)\equiv \exists x \neg P(x),\exists! x\neg P(s)$
$\therefore \exists x\neg P(x)$，则原命题成立
# Problem 4
令M(x)为谓词“x是数学专业的”，C(x)为谓词“x是计算机专业的”，$G_1$为谓词“x是新生”，$G_2$(x)为谓词“x是二年级学生”，$G_3$(x)为谓词“x是三年级学生”，$G_4$(x)为谓词“x是四年级学生”。设论域为离散数学班上的学生。
(a)$\exists x\,G_3(x)$。该命题为真
(b)$\forall x\, C(x)$。该命题为假($\because \exists x M(x)$)
(c)$\exists x (\neg M(x)\land \neg G_3(x))$。该命题为真
(d)$\forall x (G_2(x)\lor C(x))$。该命题为假（存在两个数学专业的三年级学生）
(e)$((\exists x(M(x)\land G_1(x)))\land(\exists x(M(x)\land G_2(x)))\land(\exists x(M(x)\land G_3(x)))\land(\exists x(M(x)\land G_4(x))))\lor((\exists x(M(x)\land G_1(x)))\land(\exists x(v))\land(\exists xC(x)\land G_3(x))\land(\exists xC(x)\land G_4(x)))$
该命题为假。
# Problem 5
令P(x)为谓词“x是正整数”。设论域为全体整数$\mathbb{Z}$。
$\exists x\,(P(x)\land (\forall y_1,y_2,y_3\,\,y_1^2+y_2^2+y_3^2\ne x))$
# Problem 6
证明：
$$
\begin{align*}
&(1)\forall x(P(x)\land R(x))(前提)\\
&(2)P(a)\land R(a)(全称例示\,自(1))\\
&(3)P(a)(化简)\\
&(4)R(a)(化简)\\
&(5)\forall x(P(x)\to (Q(x)\land S(x)))(前提)\\
&(6)P(a)\to(Q(a)\land S(a))(全称例示)\\
&(7)Q(a)\land S(a)(假言推理)\\
&(8)S(a)(化简)\\
&(9)R(a)\land S(a)(合取引入)\\
&(10)\forall x(R(x)\land S(x))(全称生成)\\
\end{align*}
$$
# Problem 7
证明：
$$
\begin{align*}
&(1)\exists x\neg P(x)(前提)\\
&(2)\neg P(a)(存在例示\,\,自(1))\\
&(3)\forall x(P(x)\lor Q(x))(前提)\\
&(4)P(a)\lor Q(a)(全称例示)\\
&(5)Q(a)(析取三段论\, 自(2)(4))\\
&(6)\forall x(\neg Q(x)\lor S(x))(前提)\\
&(7)\neg Q(a)\lor S(a))(全称例示)\\
&(8)S(a)(析取三段论\,\,自(5)(7))\\
&(9)\forall x(R(x)\to\neg S(x))(前提)\\
&(10)R(a)\to\neg S(a)(存在例示)\\
&(11)\neg R(a)(取拒式\,\,自(8)(10))\\
&(12)\exists x \neg P(x)(存在生成)
\end{align*}
$$
# Problem 8
$\exists x(P(x)\land(\forall y\,P(y)\to y=x))$