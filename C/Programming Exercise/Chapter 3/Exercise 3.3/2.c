#include <stdio.h>

int main()
{
    int i, j, k, x, y;
    char arr[7][7];

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            arr[i][j] = '-';
        }
    }

    for (k = 0; k < 5; k++) {
        scanf("%d %d", &x, &y);

        arr[x - 1][y - 1] = '*';
    }

    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}