import numpy as np
import matplotlib.pyplot as plt

# ask the user for matrix dimensions
rows = int(input("Enter number of rows: "))
cols = int(input("Enter number of columns: "))

# create the matrix
matrix = np.arange(1, rows * cols + 1).reshape(rows, cols)

print("\nOriginal matrix:")
print(matrix)

# ask for slicing boundaries
row_start = int(input("Enter starting row: "))
row_end = int(input("Enter ending row: "))
col_start = int(input("Enter starting column: "))
col_end = int(input("Enter ending column: "))

result = matrix[row_start:row_end, col_start:col_end]

print("\nSliced matrix:")
print(result)

# show the result graphically
plt.imshow(result, cmap="gray", interpolation="nearest")

# display values inside cells
for i in range(result.shape[0]):
    for j in range(result.shape[1]):
        plt.text(
            j,
            i,
            result[i, j],
            ha="center",
            va="center"
        )

plt.colorbar()
plt.title("NumPy Matrix Slice")
plt.show()
