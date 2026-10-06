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
