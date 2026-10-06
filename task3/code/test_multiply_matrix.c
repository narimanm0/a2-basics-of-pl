#include <stdio.h>
#include <stdlib.h>

// define our matrix sizes:
#define row_1 2 // # of rows in the 1st matrix
#define col_1 2 // # of columns in the 1st matrix
#define row_2 2 // # of rows in the 2nd matrix
#define col_2 3 // # of columns in the 2nd matrix

void multiply_matrix(int m1[][col_1], int m2[][col_2]){
    int res[row_1][col_2];

    printf("Matrix Result is:\n");

    for (int i = 0; i < row_1; i++) {
        for (int j = 0; j < col_2; j++) {
            res[i][j] = 0;

            for (int k = 0; k < row_2; k++) {
                res[i][j] += m1[i][k] * m2[k][j];
            }
            printf("%d\t", res[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    printf("Test 1: example from the program\n");
    int a1[2][2] = {{1, 1}, {2, 2}};
    int a2[2][3] = {{1, 1, 1}, {2, 2, 2}};
    printf("Expected:\n3\t3\t3\n6\t6\t6\n");
    multiply_matrix(a1, a2);

    printf("\nTest 2: numbers calculated by hand\n");
    int b1[2][2] = {{1, 2}, {3, 4}};
    int b2[2][3] = {{5, 6, 7}, {8, 9, 10}};
    printf("Expected:\n21\t24\t27\n47\t54\t61\n");
    multiply_matrix(b1, b2);

    printf("\nTest 3: identity matrix (the second matrix must not change)\n");
    int c1[2][2] = {{1, 0}, {0, 1}};
    int c2[2][3] = {{4, 5, 6}, {7, 8, 9}};
    printf("Expected:\n4\t5\t6\n7\t8\t9\n");
    multiply_matrix(c1, c2);

    printf("\nTest 4: zero matrix\n");
    int d1[2][2] = {{0, 0}, {0, 0}};
    printf("Expected:\n0\t0\t0\n0\t0\t0\n");
    multiply_matrix(d1, c2);

    printf("\nTest 5: negative numbers\n");
    int e1[2][2] = {{-1, 2}, {3, -4}};
    int e2[2][3] = {{5, -6, 0}, {-8, 9, 1}};
    printf("Expected:\n-21\t24\t2\n47\t-54\t-4\n");
    multiply_matrix(e1, e2);

    return 0;
}
