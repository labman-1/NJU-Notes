### Aggregation
Aggregation is the process of doing operations on *groups of rows* instead of just *a single row* 

| Aggregation function | return value |
| -------------------- | ------------ |
| MAX(\[columns])      |              |
| MIN(\[columns])      |              |
### Groups
You can ***GROUP BY*** any valid SQL expression, which includes using mltiple column names and operators.

```SQL
SELECT parent, AVG(age) AS avg_age FROM dogs,parents WHERE name =child GROUP BY parent HAVING MIN(age)>=5;
```

```scheme
(define (length-tail lst)
	(define (helper lst l)
		(if (null? lst)
			l
			(helper (cdr lst) (+ l 1))))
	(helper lst 0))
```

