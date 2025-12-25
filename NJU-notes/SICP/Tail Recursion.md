We say an expression is in a **tail context** if it is evaluated as the last step in the function call

- That means nothing is evaluated/applied after it is evaluated

An expression is in a tail context only if **it is the last thing evaluated** in every possible scenario(no other action is performed afterwards)
```scheme
(define (fact n)
  (define(fact-tail n result) 
    (if (<= n 1)
        result
        (fact-tail (- n 1)(* n result))))
  (fact-tail n 1))
```