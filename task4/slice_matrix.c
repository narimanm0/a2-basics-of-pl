#include <stdio.h>
#include <stdlib.h>

int main() {
    int rows, cols;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter number of columns: ");
    scanf("%d", &cols);

    int **matrix = malloc(rows * sizeof(int *));

    for (int i = 0; i < rows; i++) {
        matrix[i] = malloc(cols * sizeof(int));
    }

    // fill the matrix
    int value = 1;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = value++;
        }
    }

    printf("\nOriginal matrix:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    int row_start, row_end;
    int col_start, col_end;

    printf("\nEnter starting row: ");
    scanf("%d", &row_start);

    printf("Enter ending row: ");
    scanf("%d", &row_end);

    printf("Enter starting column: ");
    scanf("%d", &col_start);

    printf("Enter ending column: ");
    scanf("%d", &col_end);

    printf("\nSliced matrix:\n");

    for (int i = row_start; i < row_end; i++) {
        for (int j = col_start; j < col_end; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    // free allocated memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return 0;
}
