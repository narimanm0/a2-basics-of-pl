# Task 2

## 1. Running the code
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
Obviously, this result may change depending on the system and Python we are using. Currently, I am running this code with Python 3.14.4 and 64-bit Windows.

## 2. Explanation

### Why we are seeing 56 bytes for Tuple?

We know that tuple has a fixed size, which means that its elements are stored inside the object, directly after header. Tuple's header has three 8 byte fields:
- reference count;
- pointer to type of elements;
- pointer to number of elements.

In Python 3.14, there is also the 4th field, which caches the hash of tuple. Now, we can calculate why we are getting 56. First, we have header which is 24 bytes. Then we have 4 fields each consisting of 8 bytes.
```
24 + 4 * 8 = 56
```

