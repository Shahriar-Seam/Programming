#include <stdio.h>

void transpose(int arr1[5][5])
{
    int arr2[5][5];
    int r, c;

    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            arr2[c][r] = arr1[r][c];
        }
    }

    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            arr1[r][c] = arr2[r][c];
        }
    }

    return;
}

int main()
{
    int table[5][5] = {
        {6, 4, 7, 8, 9}, 
        {3, 7, 1, 9, 9},
        {8, 6, 4, 2, 7},
        {2, 4, 2, 5, 9},
        {4, 1, 6, 7, 3}
    };

    int r, c;

    transpose(table);

    for (r = 0; r < 5; r++) {
        for (c = 0; c < 5; c++) {
            printf("%d ", table[r][c]);
        }

        printf("\n");
    }

    return 0;
}