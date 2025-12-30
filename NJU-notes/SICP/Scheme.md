# Scheme

Everything in scheme is expression  
## expression  

### Atomic expressions  

self-expressions 1 1.2  \#f  
symbol x lambda  
### Combinations  

A combination is either a call expression or a special from exoression  
#### Call expression  

(\<operator>\<operand1>\<operand2>…)  
A call expression applies a procedure to some arguments.  
How to evaluate call expressions:  
1Evaluate the operator to get a procedure.  
2Evaluate all operands left to right to get the arguments.  
3Apply the procedure to the arguments.  
### some special expression  

#### define  

1(define\<name>\<expression>)  
2v2.define a function: (define(\<name>\<param1>\<param2>…)\<body>) to call that function, you need to(name param1 param2) (define (square x)(\* x x)) (define(ev x y)(/(+ x y)2)) (define (abs x)(if (\< x 0) (-x) x) )  
3(define (fact n) (if(n>1) (\* n (fact (- n 1))) 1))  
4(define (count-up n))  
#### control flow  

(if\<predicate>\<if-true>\<if-false>)  
if \<predicate>is not \#f(the only false value in scheme),then\<if-true>,else \<if-false>(if provided)  
and/or
#### lambda expression  

(lambda(\<param1>\<param2>…)\<body>)  
#### cons  

(cons x y)创建一个pair(x,y) cons(1 nil)  
car返回pair第一个元素  
cdr返回第二个元素  
#### list  

```

(list 1 2 4 5)  

```

语法糖 'a等价于(quote a)不去evaluate a的值，而是保留a本身  
scm>(cdr'(a b c))  
(b c)