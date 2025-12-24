You can create SQL tables either from scratch or from existing tables.

The following statement creates a table by specifying column names and values without referencing another table. Each `SELECT` clause specifies the values for one row, and `UNION` is used to join rows together. The `AS` clauses give a name to each column; it need not be repeated in subsequent rows after the first.
```sql
CREATE TABLE [table_name] AS   SELECT [val1] AS [column1], [val2] AS [column2], ... UNION   SELECT [val3]             , [val4]             , ... UNION   SELECT [val5]             , [val6]             , ...;

```
Let's say we want to make the following table called `big_game` which records the scores for the Big Game each year. This table has three columns: `berkeley`, `stanford`, and `year`.

|berkeley|stanford|year|
|---|---|---|
|30|7|2002|
|28|16|2003|
|17|38|2014|

We could do so with the following `CREATE TABLE` statement:

`CREATE TABLE big_game AS   SELECT 30 AS berkeley, 7 AS stanford, 2002 AS year UNION   SELECT 28,             16,            2003         UNION   SELECT 17,             38,            2014;`

[](https://sicp.pascal-lab.net/2025/labs/lab10/3.html "Previous chapter")[](https://sicp.pascal-lab.net/2025/labs/lab10/3_2.html "Next chapter")