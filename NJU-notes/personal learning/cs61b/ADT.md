**Abstract data types are defined in terms of operations not implementation.**
# BST
- For each public method e.g. put(K key, V value),create a private recursive method, e.g. put(K key, V value, Node n)
- When inserting, always set left/right pointers even if nothing is actually changing.
- Avoid "arms length base cases".Don't check if left or right is null!