# Task 3: Matrix Multiplication

## 1. Implementations

### C implementation

The C program `multiply_matrix.c` multiplies a `2x2` matrix by a `2x3` matrix. The sizes are defined with `#define`, so we can change the dimensions in one place. Matrix multiplication is based on three nested loops:
- `i` goes through the rows of the first matrix;
- `j` goes through the columns of the second matrix;
- `k` goes through the shared dimension, where `res[i][j] += m1[i][k] * m2[k][j]`.

Obviously, this is only possible when the number of columns in the first matrix is equal to the number of rows in the second one. Therefore, the program checks `col_1 != row_2` and prints a message if the sizes do not match.

### Python implementation

The Python program `multiply_matrix.py` does the same job with NumPy. Instead of three loops, we are just calling `np.dot(a, b)` once. The loops still exist, but they are executed inside NumPy's compiled C code, not by the Python interpreter.

## 2. Unit tests

The tests are in `test_multiply_matrix.c`. Each test prints the expected result first, and then the output of `multiply_matrix()`, so they can be compared. We have 5 tests:

| Test | Idea                         | Why?                                               |
|------|------------------------------|----------------------------------------------------|
| 1    | example from the program     | check that the original program works              |
| 2    | numbers calculated by hand   | check the formula with different values            |
| 3    | identity matrix              | the 2nd matrix must not change                     |
| 4    | zero matrix                  | every element of the result must be 0              |
| 5    | negative numbers             | check signs of the products and the sums           |

## 3. Code size analysis

| Version            | Lines of code | Source size (bytes) | Executable size (bytes) |
|--------------------|---------------|---------------------|-------------------------|
| C                  | 33            | 828                 | 16 152                  |
| Python (NumPy)     | 7             | 99                  | not applicable          |


The Python version is about 5 times shorter in lines and about 8 times smaller in bytes. It has no size macros, no loops and no dimension check, because NumPy raises an error when the shapes
do not match. However, the Python program needs the interpreter and NumPy, while the C executable is standalone.

## 4. Execution time analysis

One 2x2 by 2x3 multiplication takes nanoseconds, so a single run cannot be measured. Each version multiplies the matrices many times and we divide the total time by the number of runs.
The C benchmark has no `printf` inside the loop, otherwise we would measure the console and not the multiplication.

| Version                    | Runs       | Time per multiplication |
|----------------------------|------------|-------------------------|
| C, `-O0`                   | 10 000 000 | 60 ns                   |
| C, `-O2`                   | 10 000 000 | about 4.7 ns            |
| Python + NumPy (lists)     | 1 000 000  | about 3 200 ns          |
| Python + NumPy (arrays)    | 1 000 000  | about 1 000 ns          |
| Pure Python (3 loops)      | 200 000    | about 4 500 ns          |

You can ask what is `-O`s there. They are Optimization Level.

For tiny matrices C (`-O2`) is about 200-700 times faster than NumPy. NumPy has a fixed overhead per call (converting lists to arrays, checking types, dispatching), which is much
larger than the 12 multiplications themselves. Even pure Python is not much slower than `np.dot` on lists here.

The opposite case is 500x500 matrices:

| Version                                  | Time      |
|------------------------------------------|-----------|
| C, `-O2`, naive `i-j-k` loops (int)     | 0.063 s   |
| C, `-O2`, `i-k-j` loop order (int)      | 0.035 s   |
| NumPy `@`, int64                         | 0.17 s    |
| NumPy `@`, float64 (BLAS)                | 0.009 s   |

BLAS - Basic Linear Algebra Subprograms

Interestingly, NumPy is not always the winner. With integers, NumPy does not use BLAS and its loop is slower than compiled C. With floats, BLAS is about 4-7 times faster than our
C code. This is because BLAS uses blocking and SIMD, and our naive loop uses neither. At `-O0` the 500x500 C version takes 0.43 s, which shows how much the compiler flag matters.

## 5. ChatGPT Implementation

After completing my own implementation, I asked ChatGPT to implement the same matrix multiplication task independently. In the prompt, I specified that the solution should use NumPy for Python and C for the C-like implementation. I also asked it to keep the implementation general and explain the difference between the two approaches. The prompt I used was:

> Implement matrix multiplication using NumPy and C. The matrix dimensions should not be hard-coded. The user should provide the matrix dimensions and values as input. The C implementation should use nested loops for multiplication, while the Python implementation should use NumPy. Also explain the time complexity and how the two implementations are different.

The ChatGPT solution used the same basic matrix multiplication algorithm in C, because this is the standard way to multiply matrices without using a library. However, the input handling was different from my implementation. Instead of defining the matrix values directly in the source code, the ChatGPT version allowed the user to enter the dimensions and values. For Python, ChatGPT used NumPy's matrix multiplication operation:

```
result = np.dot(matrix_a, matrix_b)
```

This is different from manually implementing the three loops in Python. NumPy performs the calculation using compiled code, which is why it is generally much faster for larger matrices. I compared the results of the ChatGPT implementation with my own implementation. Both produced the same matrix multiplication results for the tested cases. The main difference was in how the matrices were provided and how the code was structured. This experiment was useful because it showed that the same mathematical operation can be implemented in different ways while still producing the same result.
