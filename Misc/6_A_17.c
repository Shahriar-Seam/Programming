#include <stdio.h>

int main()
{
    int A[5][2] = {0}, B[5][2] = {0};
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d ", 2 * A[i][j] + B[i][j]);
        }

        printf("\n");
    }

    return 0;
}