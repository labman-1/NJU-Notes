More commonly, we will create new tables by selecting specific columns that we want from existing tables by using a `SELECT` statement as follows:

`SELECT [columns] FROM [tables] WHERE [condition] ORDER BY [columns] LIMIT [limit];`

Let's break down this statement:

- `SELECT [columns]` tells SQL that we want to include the given columns in our output table; `[columns]` is a comma-separated list of column names, and `*` can be used to select all columns
- `FROM [table]` tells SQL that the columns we want to select are from the given table; see the _joins section_ to see how to select from multiple tables
- `WHERE [condition]` filters the output table by only including rows whose values satisfy the given `[condition]`, a boolean expression
- `ORDER BY [columns]` orders the rows in the output table by the given comma-separated list of columns
- `LIMIT [limit]` limits the number of rows in the output table by the integer `[limit]`

> _Note:_ We capitalize SQL keywords purely because of style convention. It makes queries much easier to read, though they will still work if you don't capitalize keywords.

Here are some examples:

Select all the contents from the `big_game` table:

`sqlite> SELECT * from big_game; 17|38|2014 28|16|2003 30|7|2002`

Select all of Berkeley's scores from the `big_game` table, but only include scores from years past 2002:

`sqlite> SELECT berkeley FROM big_game WHERE year > 2002; 28 17`

Select the scores for both schools in years that Berkeley won:

`sqlite> SELECT berkeley, stanford FROM big_game WHERE berkeley > stanford; 30|7 28|16`

Select the years that Stanford scored more than 15 points:

`sqlite> SELECT year FROM big_game WHERE stanford > 15; 2003 2014`