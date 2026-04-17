# P1
(1)3
(2)$\aleph_0$
(3)$\aleph_0$
(4)$2^{\aleph_0}$
(5)$2^{\aleph_0}$
# P2
证明：
$$
\begin{align*}
&\because \left|A\right|=\left|C\right|,\left|B\right|=\left|D\right|\\
&\therefore \exists双射函数f:A\to C,双射函数g:B\to D\\ 
&要证\left|A\times B\right|=\left|C\times D\right|,只需构造一个函数h:(A\times B)\to(C\times D),并证明h为双射函数。\\
&定义h(a,b)=(f(a),g(b)),其中a\in A,b\in B.\\
&1.证明h是单射\\
&假设h(a_1,b_1)=h(a_2,b_2),\\
&\therefore (f(a_1),g(b_1))=(f(a_2),g(b_2))\\
&\therefore f(a_1)=f(a_2),g(b_1)=g(b_2)\\
&又\because f,g为单射\\
&\therefore a_1=a_2,b_1=b_2,则h也为单射.\\
&2.证明h是满射\\
&对于陪域(C\times D)中任意一个元素(c,d),由于f和g均为满射\\
&\therefore \exists a\in A,f(a)=c,\exists b\in B,g(b)=d\\
&\therefore \exists(a,b)\in A\times B,h(a,b)=(f(a),g(b))=(c,d).\\
&\therefore h是满射\\
&由于h:(A\times B)\to(C\times D)为双射函数，所以\left|A\times B\right|=\left|C\times D\right|.
\end{align*}
$$
# P3
(1)证明：
1. 若A、B均为有穷集，显然$A\cup B$也是有穷集，故$A\cup B$必可列。
2. 若A、B中一个为有穷集、一个为无穷可列集，不妨令A为有穷集、B为无穷可列集。可以把A中的元素排在队伍最前面，然后把B的元素接在后面。因为B无限，所以这种“平移”操作可以容纳A，$A\cup B$可列。
3. 若A、B均为无穷可列集，令$B_1=B\textbackslash A$,因为B可列，所以子集$B_1$可列。而$B_1\cap A=\emptyset$且$B_1\cup A=A\cup B$。A的第一个元素对应0，第二个元素对应2，第n个元素对应2(n-1)，$B_1$的第一个元素对应1，第二个元素对应3，第n个元素对应2n-1.这样就把这两个无限集塞进了一个自然数序列。
综上，$A\cup B$是可列集。
(2)
先证明$\mathbb{N}\times\mathbb{N}$是可列的。按“坐标之和”排列$\mathbb{N}\times\mathbb{N}$中的元素，对于序偶(m,n),分配编号$f(m,n)=\frac{(m+n+1)(m+n)}{2}+m$,f为双射。由于$A\approx\mathbb{N},B\approx \mathbb{N}$,所以$A\times B\approx \mathbb{N}\times\mathbb{N}\approx\mathbb{N}$,故$A\times B$是可列集。
# P4
(a)可列无限集。记集合S={11,12,13,…},构建$f:\mathbb{N}\to S,f(n)=n+11$,显然f是双射。
(b)可列无限集。记奇负数集合为S，构建$f:\mathbb{N}\to S,f(n)=-(2n+1)$,显然f为双射。
(c)有限集。
(d)不可列集。
(e)可列无限集。构建$f:\mathbb{N}\to A\times\mathbb{Z^+}$,$$f(n)=\begin{cases}(2,\frac{n}{2}+1),n为偶数\\(3,\frac{n+1}{2}),n为奇数\end{cases}$$
(f)可列无限集。记10的整数倍的数的集合为S，构建$f:\mathbb{N}\to S$,$$f(n)=\begin{cases}5n,n为偶数\\-5(n+1),n为奇数\end{cases}$$
# P5
(a)令$A=\{a|a\in[0,1]\}\cup\{2\}$,$B=\{a|a\in[0,1]\}$,则A，B均为不可列集合，且$A-B=\{2\}$为有限集。
(b)令$A=\mathbb{R}$,$B=\mathbb{R}-\mathbb{Q}$,则A，B均为不可列集。$A-B=\mathbb{Q}$为可列无限集。
(c)令$A=\{a|a\in[0,2]\},B=\{a|a\in[0,1]\}$,则A，B均为不可列集合，$A-B=\{a|a\in[0,1)\}$，为不可列集。
# P6
(a)令A为平面直角坐标系中直线y=0上所有的点，B为平面直角坐标系中直线x=0上所有的点，则$A\cap B={(0,0)}$，为有限集。
(b)令$A=\{a|a\in[0,1]\}$，$B=\{a|a\in[2,3]\}\cup\mathbb{Q}$,则$A\cap B=\{a|a\in[0,1]\land a\in\mathbb{Q}\}$,则$A\cap B$为可列无限集
(c)令$A=\{a|a\in[0,1]\},B=\{a|a\in[0,3]\}$,则$A\cap B=A$为不可列集。
# P7
证明：
由于A是可列集，所以$\exists \text{双射}g:\mathbb{N}\to A$。若存在一个从A到B的满射函数f，则$\forall b\in B,\exists a\in A,f(a)=b$，所以$\forall b\in B,\exists n\in\mathbb{N},f(g(n))=f(a)=b$,令h(n)=f(g(n))，则h为满射函数。对于B中的每一个元素b，其原像集$h^{-1}(b)$显然非空，在每个原像集中选择最小的自然数，定义$k:B\to \mathbb{N},k(b)=min\{n\in\mathbb{N}|h(n)=b\}$，显然不同的b对应不同的最小自然数，所以k是一个单射。所以$B\approx range(k)\subseteq\mathbb{N}$，B为可列集。
# P8
证明：对于A的任意一个子集$S\in\mathcal{P}(A)$,令它对应一个函数$f_S$,$$f_S(x)=\begin{cases}1,x\in S\\ 0,x\not\in S \end{cases}$$.下面证明这个构造为双射。
先证明该函数为单射。假设有两个不同的子集$S_1,S_2\in\mathcal{P}$，则不妨假设$\exists x\in S_1,x\not\in S_2$,则$f_{S_1}(x)=1,f_{S_2}(x)=0$,，则$f_{S_1}与f_{S_2}$不是同一个函数，单射成立。
再证明满射。
$\forall h\in\{0,1\}^A,令S=\{x\in A|h(x)=1\}$,显然S是A的子集且S对应的函数为$f_S$，所以陪域里的每一个函数h都有“原像”S，满射成立。
综上，$成功构建出了双射函数g(S)=f_S,则\mathcal{P}(A)\approx\{0,1\}^A$.

