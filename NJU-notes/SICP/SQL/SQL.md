### Aggregation
Aggregation is the process of doing operations on *groups of rows* instead of just *a single row* 

| Aggregation function | return value |
| -------------------- | ------------ |
| MAX(\[columns])      |              |
| MIN(\[columns])      |              |
### Groups
You can ***GROUP BY*** any valid SQL expression, which includes using mltiple column names and operators.

```SQL
SELECT fur, avg(height) FROM dogs_heights
	GROUP BY fur;
```


