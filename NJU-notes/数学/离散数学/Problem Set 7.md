# P1
(a)是
(b)是
(c)不是。对于n=0没有对应的映射结果
# P2
(a)不是
(b)不是
(c)是
(d)是
# P3
(a)令$x^2+2x=1$，解得$x=-1\pm\sqrt2$，所以$f^{-1}(\{1\})=\{-1+\sqrt2,-1-\sqrt2\}$
(b)令$0<x^2+2x<1$，解得$\{x|-1-\sqrt2<x<-2\lor0<x<-1+\sqrt2\}$，所以$f^{-1}(\{x|0<x<1\})=\{x|-1-\sqrt2<x<-2\lor0<x<-1+\sqrt2\}$
(c)
令$3<x^2+2x$，解得$\{x|x<-3\lor x>1\}$，所以$f^{-1}(\{x|x>3\})=\{x|x<-3\lor x>1\}$
# P4
证明：
先证单射：
若$f(x_1,y_1)=f(x_2,y_2)$，则$(x_1+y_1,x_1-y_1)=(x_2+y_2,x_2-y_2)$，由关系的性质知$(x_1+y_1,x_1-y_1)=(x_2+y_2,x_2-y_2)$当且仅当$x_1+y_1=x_2+y_2,x_1-y_1=x_2-y_2$，可得$x_1=x_2,y_1=y_2$，单射得证。
下证满射：
假设陪域中任意一个序偶为(u,v)，令x+y=u,x-y=v，解得$x=\frac{u+v}{2},y=\frac{u-v}{2}$，因为u，v是实数，所以x，y一定为实数,$(x,y)\in\mathbb{R}\times\mathbb{R}$，故f为满射。
综上所述，f为双射函数。
# P5
(a)定义域为$\mathbb{Z_+}$，值域为$\mathbb{Z_+}$
(b)定义域为扑克牌（不含大小王），值域为红桃，方片，梅花，黑桃四种花色。
(c)定义域为所有可能的位串，值域为$\mathbb{N}$
(d)定义域为$\mathbb{Z_+}$，值域为{0，1}
# P6
(a)是
(b)是
(c)是
(d)不是
(e)不是
# P7
证明：
由于A和B是有限集，若f是单射，则$\left|f(A)\right|=\left|A\right|$,又因为$\left|A\right|=\left|B\right|$,所以$\left|f(A)\right|=\left|B\right|$,又因为$f(A)\subseteq B$，所以$f(A)=B$，即f为满射。
若f是满射，假设f不是单射，则$\exists a_1,a_2\in A,a_1\neq a_2,f(a_1)=f(a_2)$, 所以$\left|f(A)\right|<\left|A\right|=\left|B\right|$,则$f(A)\neq B$，这与满射矛盾，故假设不成立，f为单射。
综上，f是单射当且仅当它是满射。
# P8
证明：
假设f不是单射，则$\exists x,y\in A,x\neq y,f(x)=f(y)$,由函数性质知$g(f(x))=g(f(y))$，这与$g\circ f$为单射矛盾，故假设不成立，f为单射。
# P9
证明：
$$
\begin{align*}
\forall x\in f^{-1}(\overline S)\Leftrightarrow f(x)\in\overline S\Leftrightarrow f(x)\not\in S\Leftrightarrow\neg(f(x)\in S)\Leftrightarrow\neg(x\in f^{-1}(S))\Leftrightarrow x\not\in f^{-1}(S)\Leftrightarrow x\in\overline{f^{-1}(S)}
\end{align*}
$$
则$f^{-1}(\overline S)=\overline{f^{-1}(S)}$
# P10
证明：
