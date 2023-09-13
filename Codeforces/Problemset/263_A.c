#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;
    int a, b, min;
    int arr[5][5];

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (arr[i][j] == 1) {
                a = i;
                b = j;

                break;
            }
        }
    }

    min = abs(a - 2) + abs(b - 2);

    printf("%d", min);

    return 0;
}