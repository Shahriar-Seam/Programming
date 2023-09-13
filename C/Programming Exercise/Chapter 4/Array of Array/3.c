#include <stdio.h>

int main()
{
    int numbers[3][5], total[3] = {0};
    int  i, j;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &numbers[i][j]);
            total[i] += numbers[i][j];
        }
    }

    for (i = 0; i < 3; i++) {
        printf("Subject %d:\tAverage: %g\n", i + 1, (double) total[i] / 5);
    }

    return 0;
}