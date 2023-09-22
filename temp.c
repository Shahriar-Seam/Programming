#include <stdio.h>

int main() {
    int a[10][10], b[10][10], result[10][10];
    int r1, c1, r2, c2, i, j, k, sum;

    printf("Enter rows and columns of matrix A: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter rows and columns of matrix B: ");
    scanf("%d%d", &r2, &c2);

    // Check if matrices can be multiplied
    while (c1 != r2) {
        printf("Error\n");
        printf("Enter rows and columns of matrix A: ");
        scanf("%d%d", &r1, &c1);

        printf("Enter rows and columns of matrix B: ");
        scanf("%d%d", &r2, &c2);
    }

    // Take input
    printf("Enter elements for matrix A:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter elements for matrix B:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Print the matrixes
    printf("Matrix A:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            printf("%d\t", a[i][j]);
        }

        printf("\n");
    }

    printf("Matrix B:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d\t", b[i][j]);
        }

        printf("\n");
    }

    // Perform matrix multiplication
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            sum = 0;
            for (k = 0; k < c1; k++) {
                sum = sum a[i][k] * b[k][j];
            }
            result[i][j] = sum;
        }
    }

    // Print the result matrix
    printf("\nResult matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
