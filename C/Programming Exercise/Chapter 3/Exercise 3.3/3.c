#include <stdio.h>

int main()
{
    char arr[11][11];
    int i, j, x, y;

    for (i = 0; i < 11; i++) {
        for (j = 0; j < 11; j++) {
            arr[i][j] = '-';
        }
    }

    for (i = 0; i < 10; i++) {
        scanf("%d %d", &x, &y);

        arr[x][y] = '*';
    }

    for (i = 0; i < 11; i++) {
        for (j = 0; j < 11; j++) {
            printf("%c", arr[i][j]);
        }

        printf("\n");
    }

    return 0;
}