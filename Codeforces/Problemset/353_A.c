#include <stdio.h>

void swap(int *a, int *b)
{
    *a ^= *b ^= *a ^= *b;
}

int main()
{
    int n, i, count = 0;
    int x, y, up = 0, down = 0;

    scanf("%d", &n);

    int arr[n][2];

    for (i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);

        arr[i][0] = x;
        arr[i][1] = y;

        if (x % 2 == 1) {
            up++;
        }
        if (y % 2 == 1) {
            down++;
        }
    }
    
    if ((up % 2 == 0) && (down % 2 == 0)) {
        x = 0;
        y = 0;

        for (i = 0; i < n; i++) {
            x += arr[i][0];
            y += arr[i][1];
        }

        printf("%d\n", ((x % 2 == 1) || (y % 2 == 1) ? -1 : 0));
    }
    else if ((up > 0 && down == 0) || (up == 0 && down > 0)) {
        printf("-1\n");
    }
    else {
        for (i = 0; i < n; i++) {
            if ((arr[i][0] % 2) != (arr[i][1] % 2)) {
                swap(&arr[i][0], &arr[i][1]);

                break;
            }
        }

        x = 0;
        y = 0;

        for (i = 0; i < n; i++) {
            x += arr[i][0];
            y += arr[i][1];
        }

        printf("%d\n", ((x % 2 == 1) || (y % 2 == 1) ? -1 : 1));
    }

    return 0;
}