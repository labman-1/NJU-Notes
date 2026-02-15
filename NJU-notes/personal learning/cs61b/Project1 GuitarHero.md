## Packages
A package is a collection of Java classes that all work together towards some common goal. 
When creating a package, we specify that code is part of a package by specifying the package name at the top of the file uing the **package** keyword.   `package deque;`
If a programmer wanted to use a class or a method from our `deque` package, they would have to either use the full canonical name, e.g. `deque.ArrayDeque`, or alternately use `import deque.ArrayDeque`, at witch point they could just use the simple name `ArrayDeque`. So `import` statements just allow you to use the simple name of a class/method.
Typically, package names are the internet address of the entity writing the code, but backwards. For example, the JUnit library is hosted at `junit.org`, so the package is called `org.junit`.
### Benefits of packages
Since there are no two programmers use the same package name for their package, we can freely use the same class name in several different
contexts. Given the requirement to either use the full canonical name or to use an import, this means we'll never accidfentally use one class when we meant to use another.
### Rules of thumb about generics
- In the .java file implementing your data structure, specify your “generic type” only once at the very top of the file.
    
- In .java files that use your data structure, specify desired type once:
- Write out desired type during declaration.
- Use the empty diamond operator <> during instantiation.

- When declaring or instantiating your data structure, use the reference type.
- int: Integer
    
- double: Double
    
- char: Character
    
- boolean: Boolean
    
- long: Long
    
- etc. 