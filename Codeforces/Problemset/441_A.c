#include <stdio.h>

int main()
{
    int n, v, k, temp;
    int f, i, j = 0;
    int arr[55] = {};

    scanf("%d %d", &n, &v);

    for (i = 1; i <= n; i++) {
        scanf("%d", &k);

        f = 0;

        while (k--) {
            scanf("%d", &temp);

            if (v > temp) {
                f = 1;
            }
        }

        if (f == 1) {
            arr[j++] = i;
        }
    }

    printf("%d\n", j);

    if (j > 0) {
        for (i = 0; i < j; i++) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}