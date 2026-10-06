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

int main(){
    // let's define the matrices
    int m1[row_1][col_1] = { { 1, 1 }, { 2, 2 } };
    int m2[row_1][col_2] = { { 1, 1, 1 }, { 2, 2, 2 } };

    // if coloumn of m1 not equal to rows of m2
    if (col_1 != row_2) {
        printf("# of columns in the 1st matrix must be = to # of rows in the 2nd matrix\n");
        printf("Update values you added according to your array dimension in #define section\n");
    }

    multiply_matrix(m1, m2);

    return 0;
}
