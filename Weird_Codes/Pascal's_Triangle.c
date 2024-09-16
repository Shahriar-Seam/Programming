#include <stdio.h>

int main()
{
    int n, r, c, i, j;

    scanf("%d", &n);

    r = n + 1;
    c = n + 1;

    int arr[r][c];

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            arr[i][j] = 0;
        }
    }

    arr[0][0] = 1;

    for (i = 1; i < r; i++) {
        arr[i][0] = 1;

        for (j = 1; j < c; j++) {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < i + 1; j++) {
            printf("%d ", arr[i][j]);
        }

        printf("\n");
    }

    return 0;
}