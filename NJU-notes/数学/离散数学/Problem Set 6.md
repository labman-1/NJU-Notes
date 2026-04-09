# P1
(a)正确
(b)错误
(c)错误
(d)正确
# P2
证明：
原命题等价于$A=B\to A\times B=B\times A,其中A和B均为非空集合$
充分性：
若A=B，$\forall (x,y)\in A\times B,\, (x\in B)\land (y\in A),\therefore (x,y)\in B\times A$
$\therefore A\times B\subseteq B\times A$
同理可证$\therefore B\times A\subseteq A\times B$
$\therefore A\times B=B\times A$
必要性：
$若 A\times B=B\times A,\because A,B非空,设b\in B,\therefore \forall a\in A有(a,b)\in A\times B=B\times A\Rightarrow\, a\in B$
故$A\subseteq B$。同理可得$B\subseteq A$，故A=B.
则原命题得证。
# P3
(a)$R^{-1}=\{(b,a)|a整除b,a,b\in\mathbb{Z^+}\}$
(b)$\overline R=\{(a,b)|a不能整除b,a,b\in\mathbb{Z^+}\}$
# P4
![[Screenshot_2026-04-09-16-43-23-140_com.onyx.galax.jpg]]
通过映射关系可知$S\circ R=\{(1,1),(1,2),(2,1),(2,2)\}$
# P5
$R^2=R\circ R$，由于$(a,b)\in R当且仅当a是b的导师$，所以当且仅当a是b的论文导师的论文导师时，有$(a,b)\in R^2$。
$当存在具有博士学位的n-1个人x_1,x_2,…,x_{n-1},使得a是x_1的导师,x_1是x_2的导师，…，且x_{n-1}是b的导师时，(a,b)\in R^n$
# P6
$R1=\{(a,b)|a-b=3k,k\in \mathbb{Z}\},R2=\{(a,b)|a-b=4k,k\in\mathbb{Z}\}$
(a)$R_1\cup R_2=\{(a,b)|a\equiv b(mod\, 3)\lor a\equiv b(mod\, 4)\}$
(b)$(a,b)\in R_1\cap R_2\Leftrightarrow a\equiv b(mod\,3)\land  a\equiv b(mod\,4)\Leftrightarrow 3|(a-b)\land 4|(a-b)\Leftrightarrow lcm(3,4)|(a-b)\Leftrightarrow 12|(a-b)$
$\therefore R_1\cap R_2=\{(a,b)|a\equiv b(mod\, 12)\}$
(c)$R_1-R_2=\{(a,b)|a\equiv b(mod\,3)\land a\not\equiv b(mod\,4)\}$
(d)$R_2-R_1=\{(a,b)|a\equiv b(mod\,4)\land a\not\equiv b(mod\,3)\}$
(e)$R_1\oplus R_2=R_1\cup R_2-R_1\cap R_2=\{(a,b)|(a\equiv b(mod\, 3)\lor a\equiv b(mod\, 4))\land a\not\equiv b(mod\, 12)\}$
# P7
(a)共有$2^{16}$个不同的二元关系
(b)共有$2^15$个二元关系包含有序对