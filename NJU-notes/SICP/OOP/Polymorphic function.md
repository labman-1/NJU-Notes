## What is Polymorphic function:

A function that applies to many (poly) different forms (morph)

就是传入parameter后找到对应的type，再调用对应的特殊函数

内置函数__str__是给人看的，而__repr__是给计算机看的

### str and repe

There are two main ways to produce the "string" of an object in Python: `str()` and `repr()`. While the two are similar, they are used for different purposes.

`str()` is used to describe the object to the end user in a "Human-readable" form, while `repr()` can be thought of as a "Computer-readable" form mainly used for debugging and development.

When we define a class in Python, `__str__` and `__repr__` are both built-in methods for the class.

We can call those methods using the global built-in functions `str(obj)` or `repr(obj)` instead of dot notation, `obj.__repr__()` or `obj.__str__()`.

In addition, the `print()` function calls the `__str__` method of the object, while simply calling the object in interactive mode calls the `__repr__` method.

Here's an example:
```python
class Rational:

    def __init__(self, numerator, denominator):
        self.numerator = numerator
        self.denominator = denominator

    def __str__(self):
        return f'{self.numerator}/{self.denominator}'

    def __repr__(self):
        return f'Rational({self.numerator},{self.denominator})'
```
## The myths ofprint()

We have learnt that, when dealing with string values, `print` and `return` behaves differently for the same string. For example:
```python
>>> def using_print():
...     print('hello')
...
>>> def using_return():
...     return 'hello'
...
>>> using_print()
hello
>>> using_return()
'hello'
```
For `using_print('hello')`, `print` will first call the `__str__` method of its argument (`str('hello')`) to obtain its human-readable form. When the resulting human-readable form `'hello'` is obtained, `print` displays its **contents** to the terminal, which is `hello`.

For `using_return('hello')`, this expression evaluates to a string value, which is `'hello'`. Since we are in the inetractive mode, Python will call the `__repr__` method of `'hello'` (`repr('hello')`) to obtain its computer-readable form for debugging and development. When the resulting computer-readable form `"'hello'"` is obtained (note the number of quotes appeared), Python displays the **contents** of the resulting string to the terminal, which gives `'hello'`.

Simply put, `print(x)` displays the contents of `str(x)`, whereas evaluating `x` in the interactive terminal is roughly equivalent to `print(repr(x))`.