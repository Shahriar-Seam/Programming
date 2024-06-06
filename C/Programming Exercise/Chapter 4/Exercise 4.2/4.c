#include <stdio.h>

int main()
{
    int result[5][4];
    double grade[5][4];
    int i, j;

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &result[i][j]);
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 4; j++) {
            if (result[i][j] >= 80) {
                grade[i][j] = 5;
            }
            else if (result[i][j] >= 70) {
                grade[i][j] = 4;
            }
            else if (result[i][j] >= 60) {
                grade[i][j] = 3.5;
            }
            else if (result[i][j] >= 50) {
                grade[i][j] = 3;
            }
            else if (result[i][j] >= 40) {
                grade[i][j] = 2;
            }
            else if (result[i][j] >= 33) {
                grade[i][j] = 1;
            }
            else {
                grade[i][j] = 0;
            }
        }
    }

    for (i = 0; i < 5; i++) {
        printf("\nStudent %d:\t", i);

        for (j = 0; j < 4; j++) {
            printf("%g\t", grade[i][j]);
        }
    }

    printf("\n");

    return 0;
}