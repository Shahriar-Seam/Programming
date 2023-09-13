#include <stdio.h>
#include <math.h>

int main()
{
    int ara1[5][5];
    int ara2[5][5];
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            ara1[i][j] = (j + 1) * pow(10, i);
        }
    }
    
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d\t", ara1[i][j]);
        }

        printf("\n");
    }

    printf("-------------------------------------\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            ara2[i][j] = ara1[j][i];
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d\t", ara2[i][j]);
        }

        printf("\n");
    }

    return 0;
}