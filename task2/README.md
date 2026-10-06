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


### Why we are seeing 72 bytes for List?

In the case of List, it can grow/shrink, which means that its elements cannot be stored inside the object. List's object holds:
- pointer to a separate array of elements of pointers;
- counter of the slots in the array.
So, the calculation is the following:
```
24 (header) + 8 * 2 = 40
```
But why not 72? Because `__sizeof__()` adds size of the separate array that list points to. This array has `allocated * 8` bytes. What is `allocated`? It is the number of slots (not number of elements). In our case, [1,2,3] has 4 slots. Therefore, we need to do calculation again:
```
24 + 4 * 8 + 8 = 72
```
