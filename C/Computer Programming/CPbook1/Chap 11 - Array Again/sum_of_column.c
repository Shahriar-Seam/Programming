#include <stdio.h>

int main()
{
    int table[5][5] = {
        {6, 4, 7, 8, 9}, 
        {3, 7, 1, 9, 9},
        {8, 6, 4, 2, 7},
        {2, 4, 2, 5, 9},
        {4, 1, 6, 7, 3}
    };
    int i, j, sum;
    for (j = 0; j < 5; j++) {
        sum = 0;

        for (i = 0; i < 5;i++) {
            sum += table[i][j];
        }

        printf("Sum of column %d: %d\n", j + 1, sum);
    }

    return 1;
}