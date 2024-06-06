#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, n, k, *arr, count, i, j;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &k);

        arr = (int *) malloc(sizeof(int) * n);
        count = 0;

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        for (i = 0; i + k <= n; i++) {
            for (j = i; j < i + k; j++) {
                if (arr[j] & 1 == 1) {
                    count++;
                    break;
                }
            }
        }

        printf("%d\n", count);
    }

    return 0;
}