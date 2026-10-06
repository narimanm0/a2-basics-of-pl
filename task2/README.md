# Task 2

Let's first run the following code:

```
tpl = (1, 2, 3)
tpl.__sizeof__()
lst = [1, 2, 3]
lst.__sizeof__()
```

Actually, when we run it, we do not see any result, so I added `print()` function to see the results:
```
tpl = (1, 2, 3)
print(tpl.__sizeof__())
lst = [1, 2, 3]
print(lst.__sizeof__())
```
Output:
```
56
72
```
