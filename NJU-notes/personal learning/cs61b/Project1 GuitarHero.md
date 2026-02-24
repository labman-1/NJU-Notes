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
## the Karplus-Strong algorithm
The two primary components that make the Karplus-Strong algorithm work are the ring buffer feedback mechanism and the averaging operation.

- **The ring buffer feedback mechanism**. The ring buffer models the medium (a string tied down at both ends) in which the energy travels back and forth. The length of the ring buffer determines the fundamental frequency of the resulting sound. Sonically, the feedback mechanism reinforces only the fundamental frequency and its harmonics (frequencies at integer multiples of the fundamental). The energy decay factor (.996 in this case) models the slight dissipation in energy as the wave makes a round trip through the string.
- **The averaging operation**. The averaging operation serves as a gentle low-pass filter (which removes higher frequencies while allowing lower frequencies to pass, hence the name). Because it is in the path of the feedback, this has the effect of gradually attenuating the higher harmonics while keeping the lower ones, which corresponds closely with how a plucked guitar string sounds.