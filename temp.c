#include <stdio.h>

int main()
{
    int highest, sum = 0;
    int matrix[100][100];
    int i, j;

    for (i = 0; i < 100; i++) {
        for (j = 0; j < 100; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (i = 0; i < 100; i++) {
        highest = matrix[i][0];

        for (j = 0; j < 100; j++) {
            if (matrix[i][j] > highest) {
                highest = matrix[i][j];
            }
        }

        sum = sum + highest;
    }

    printf("Sum = %d\n", sum);

    return 0;
}