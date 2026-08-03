# 1
**Programming is an act of almost pure creativity!**
The greatest limitation we face in building systems is being able to understand what we're building!
Tools like IntelliJ make it easier to deal with complexity.
- But our most important goal is to keep our software **simple**.
## Dealing with Complexity
There are two approaches to managing complexity:
- Making code simpler and more obvious.
	- Eliminating special cases, e.g. sentinel nodes.
- Encapsulation into modules.
	- In a modular design, creators of one "module" can use other module without knowing how they worl.

**"Complexity is anytihng related to the structure of a software system that makes it hard to understand and modify the system."**
![[Software Engineering_202607282342.png]]
![[Software Engineering_202607290014.png]]
![[Software Engineering_202607290015.png]]

# 2
***Your code should reads like a story***
There are two primary sources of complexity:
- **Dependencies**: When a piece of code cannot be read, understood, and modified independently.
- **obscurity**: When important information is not obvious.

## Hiding Complexity
Manage complexity: design your system so that programmer is only thinking about some of the complexity at once.
- Using helper methods and helper class that hides complexity.
![[Software Engineering_202608032348.png]]
![[Software Engineering_202608032348-1.png]]
The most important way to make your modules deep is to practice "information hiding".
- Embed knowledge and design decision in the module itself, without exposing them to the outside woeld.

Reduces complexity in two ways:
- Simplifies interface.
- Makes it easier to modify the system.



