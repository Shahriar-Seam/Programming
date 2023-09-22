#include <stdio.h>

int main()
{
    int matA[3][3] = {0};
    int matB[3][3] = {0};
    int matR[3][3] = {0};
    int i, j, k;

    printf("Enter elements of matrix A:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matA[i][j]);
        }
    }
    
    printf("Enter elements of matrix B:\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf("%d", &matB[i][j]);
        }
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            matR[i][j] = 0;

            for (k = 0; k < 3; k++) {
                matR[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    
    printf("A x B:\n\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", matR[i][j]);
        }

        printf("\n");
    }

    return 0;
}