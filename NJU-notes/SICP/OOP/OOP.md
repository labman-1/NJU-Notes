## Encapsulation
核心：把数据（attribute）和操作数据的代码（method）绑定，并对外部隐藏实现细节。关键在于**访问控制 

Why we need Encapsulation:

- Protect data security
- Reduce coupling
- ```python
  class Account:
    """
    Instance Attributes:
        balance: the money left in this account
        holder: the holder of this account
    Class Attributes:
        interest: the interest rate of all accounts
    """

    # class attribute
    interest = 0.02

    # constructor
    def __init__(self, account_holder): 
        self.balance = 0 # instance attribute
        self.holder = account_holder
    
    # methods
    def deposit(self, amount): 
        self.balance += amount
        return self.balance
    
    def withdraw(self, amount):
        if amount > self.balance:
            return 'Insufficient funds'
        self.balance -= amount
        return self.balance

jacy = Account('Jacy') 
"""
>>> jacy.balance
0
>>> jacy.deposit(10)
10
>>> jacy.withdraw(5)
5
"""
  ```
 
### Evaluation of Dot Expression

`<expression>.<name>`

Evaluatethe `<expression>` to the left of the dot, which returns the object of the expression.

`<name>` is matched against the instance attributes of that object; if an attribute with that name exists, its value is returned.

If not, `<name>` is looked up in the class, which yields a class attribute value (if no such class attribute exists, an AttributeError is reported).

That value is returned unless it is a function, in which case a bound method is returned instead.
```python
class Human:
    age = 0 # class attribute
    def grow(self):  
        self.age += 1   # create an object attribute age

```
## Inheritance
核心：代码复用。Derived Class automatically owns the attributes and methods of its parent class.
```python
class Animal:
    name = "Animal"
    def eat(self):
        print("吃吃吃吃吃吃吃吃吃")

class Dog(Animal):  # 继承 Animal
    def bark(self):
        print("汪汪汪汪汪汪汪汪汪")

dog = Dog()
dog.eat()   # 继承自父类的方法
dog.bark()  # 自己的方法
```
### Class Attributes Lookup

To look up a name in a class:

1. If it names an attribute in the class, return the attribute value.
2. Otherwise, look up the name in the base class, if there is one.
```python
class A:
    z = -1
    def f(self, x):
        return B(x - 1)
    def __repr__(self):
        return 'A()'
    
class B(A):
    n = 4
    def __init__ (self, y):
        if y:
            self.z = self.f(y)
        else:
            self.z = C(y + 1)
    def __repr__(self):
        return f'B(z={self.z})'

class C(B):
    def f(self, x):
        return x
    def __repr__(self):
        return f'C(z={self.z})'

a = A()
b = B(1)
b.n = 5

"""
>>> C(2).n
4
>>> a.z == C.z
True
>>> a.z == b.z
False
>>> b
B(z=B(z=C(z=1)))
>>> b.z
B(z=C(z=1))
>>> b.z.z
C(z=1)
>>> b.z.z.z
1
>>> b.z.z.z.z
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
AttributeError: 'int' object has no attribute 'z'
```
### Liskov Substitution Principle

Core principle:Wherever a base class appears, it can be replaced by a subclass without affecting the functionality of the program.
```python
class Animal:
    def speak(self):
        print("叫叫叫叫叫叫叫叫")

class Dog(Animal):
    def speak(self):
        print("汪汪汪汪汪汪汪汪")

class Cat(Animal):
    def speak(self):
        print("喵喵喵喵喵喵喵喵")

def make_sound(animal: Animal):
    animal.speak()

class Human(Animal):
    def speak(self, emotion):
        print("想成为人类")
make_sound(Animal())
make_sound(Dog())
make_sound(Cat())
make_sound(Human())
```
## Ploymorphism

#### 特设多态 Ad-Hoc Polymorphism

- polymorphic function(`__str__,__repr__ )
- operator overloading（` __add__）

#### Parametric Polymorphism
e.g., Generic functions: 
`Template T foo(T x, T y) { return (x > y) ? x : y; }

#### Inclusion Polymorphism

### Polymorphic Function

`repr(x)` behaves differently (i.e. polymorphically) when applied to different types of `x`.

- String representation for the python interpreter.
- Find the class attribute `__repr__`

`str(x)` behaves differently (i.e. polymorphically) when applied to different types of `x`.

- String representation for the human interpreter
- Find the class attribute `__str__`, if there is one, find the class attribute `__repr__`
```python
class Link:
    empty = ()
    def __init__(self, first, rest=empty):
        assert rest is Link.empty or isinstance(rest, Link)
        self.first = first
        self.rest = rest
    def __repr__(self):
        if self.rest is not Link.empty:
            rest_repr = ', ' + repr(self.rest)
        else:
            rest_repr = ''
        return 'Link(' + repr(self.first) + rest_repr + ')'
    def __str__(self):
        string = '<'
        while self.rest is not Link.empty:
            string += str(self.first) + ' '
            self = self.rest
        return string + str(self.first) + '>'
    
s = Link(1, Link(2, Link(3)))
t = Link(-1, Link(-2, Link(-3)))
```
### Operator Overloading

`x + y` is essentially `x.__add__(y)`.

`x == y` is essentially `x.__eq__(y)`.
```python
class Link:
    empty = ()

    ...
    
    def __add__(self, other):
        if self is Link.empty or other is Link.empty:
            return Link.empty
        return Link(self.first + other.first, self.rest + other.rest)
    
    def __eq__(self, other):
        if self is Link.empty and other is Link.empty:
            return True
        if self is Link.empty or other is Link.empty:
            return False
        return self.first == other.first and self.rest == other.rest
    
s1 = Link(1, Link(2, Link(3)))
s2 = Link(1, Link(2, Link(3)))

"""
>>> s1 + s2
Link(2, Link(4, Link(6)))
>>> s1 is s2
False
>>> s1 == s2
True
>>> s1 + s2 == Link(2, Link(4, Link(6)))
True
"""
```

| 特性           | Overloading (重载)         | Overriding (覆写)           |
| ------------ | ------------------------ | ------------------------- |
| **发生范围**     | 同一个类中                    | 父子类之间 (继承关系)              |
| **函数签名**     | 函数名相同，**参数必须不同**         | 函数名、参数**必须完全相同**          |
| **绑定时间**     | **编译时** (Static Binding) | **运行时** (Dynamic Binding) |
| **多态类型**     | 静态多态 (Compile-time)      | 动态多态 (Run-time)           |
| **Python支持** | **不支持** (用默认参数模拟)        | **天然支持**                  |

## Methods and Functions
Python distinguishes between: 
• **Functions**, which we have been creating since the beginning of the course, and 
• **Bound methods** , which couple together a function and the object on which that method will be invoked 
Object + Function= Bound Method 
```
>>> type(Account.deposit)
<class 'function'>
>>> type(tom_account.deposit) 
<class 'method'>
>>> Account.deposit(tom_account, 1000) 
1000
>>> tom_account.deposit(1021) 
2021
```
通过instance.method的方式invoke就是method，使用class.sth就是function，前者无需知道对谁操作，实现了很好的**封装**；后者需要显示传入对象作为self参数，接收方必须知道对哪个对象操作。 

## Looking Up Attributes by Name . 
To evaluate a dot expression: 
1. Evaluate the to the left of the dot, which yields the object of the dot expression 
2. is matched against the instance attributes of that object; if an attribute with that name exists, its value is returned 
3. If not, is looked up in the class, which yields a class attribute value (if no such class attribute exists, an AttributeError is reported) 
4. That value is returned unless it is a function, in which case a bound method is returned instead