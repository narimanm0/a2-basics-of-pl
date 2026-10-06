# Task 4

## 1. Implementations

For this task, I implemented 2D matrix slicing in Python using NumPy and in C. The main goal was to perform the same slicing operation in both languages and check whether they produce the same result. The matrix size is not hard-coded. The user enters the number of rows and columns, and then enters the starting and ending positions for rows and columns.

### Python implementation

In Python, NumPy makes 2D slicing very simple. The main operation is:

```python
result = matrix[row_start:row_end, col_start:col_end]
```

The first part selects the rows and the second part selects the columns.

For example, if we have:

```text
1  2  3  4  5
6  7  8  9  10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25
```

and select rows `1` to `4` and columns `2` to `5`, the result is:

```text
8   9   10
13  14  15
18  19  20
```

The Python program also displays the sliced matrix as a grayscale image using Matplotlib.

### C implementation

C does not have NumPy-style matrix slicing, so I implemented it using nested loops.

The important part is:

```c
for (int i = row_start; i < row_end; i++) {
    for (int j = col_start; j < col_end; j++) {
        printf("%4d", matrix[i][j]);
    }
}
```

The program dynamically allocates the matrix based on the dimensions entered by the user. Therefore, the program is not limited to one specific matrix size.

## 2. Results

I tested the program using the following inputs:

```text
5
5
1
4
2
5
```

These inputs mean that I created a `5 x 5` matrix and selected rows `1` to `4` and columns `2` to `5`.

The original matrix was:

```text
1   2   3   4   5
6   7   8   9   10
11  12  13  14  15
16  17  18  19  20
21  22  23  24  25
```

The resulting sliced matrix was:

```text
8   9   10
13  14  15
18  19  20
```

The Python implementation also displays the sliced matrix graphically. The values are shown inside the cells so that the graphical result can be easily compared with the printed matrix.

![Graphical result of the NumPy matrix slice](matrix_slice.png)

The graphical result shows the same values as the printed output, so the slicing operation was performed correctly.

## 3. Comparison

The main difference between the two implementations is how slicing is performed. NumPy provides slicing directly through its array syntax:

```python
matrix[row_start:row_end, col_start:col_end]
```

In C, the same operation has to be implemented manually using two loops. For this simple operation, the Python implementation is shorter and easier to understand. However, C gives more direct control over memory and does not require an external numerical library. Both implementations gave the same result for the tested matrix and slicing boundaries.

## 4. Conclusion

This task showed how the same 2D matrix slicing operation can be implemented differently in Python and C. NumPy makes the operation very short, while C requires explicit loops. The most important part was using the same row and column boundaries in both programs. The results were the same, which shows that both implementations perform the required 2D slicing correctly. The graphical output also makes the sliced matrix easier to see and compare.

## 5. ChatGPT Implementation

After completing my own implementation, I asked ChatGPT to solve the same task independently. I gave it the main requirements of the assignment: implement 2D matrix slicing in NumPy and C, allow the user to enter the matrix dimensions and slicing boundaries, and show the Python result graphically. The solution suggested by ChatGPT was somewhat different from my implementation. In the C version, instead of using a separate pointer for every row, it used one dynamically allocated block of memory for the whole matrix. An element was accessed using its row and column position.

For example:

```
matrix[i * cols + j]
```

The Python version still used NumPy slicing because NumPy already provides this functionality directly. The prompt I used was:

> Implement Task 4 independently using NumPy and C. The program should perform 2D matrix slicing. Do not read any external files or images. The user should enter the matrix dimensions and the slicing boundaries. In C, use dynamic memory and do not hard-code a particular matrix size. In Python, use NumPy and display the sliced matrix graphically. Please use a different implementation approach from a simple 2D pointer array in C.

I compared the ChatGPT solution with my own implementation. Although the internal C implementations were different, both programs performed the same slicing operation and produced the same result. This helped me verify that my implementation was correct.

