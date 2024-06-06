#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (* (int *) a - * (int *) b);
}

int main()
{
    int t, n, *arr, i, k, f;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        arr = (int *) malloc(sizeof(int) * n);

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        qsort(arr, n, sizeof(int), compare);

        k = arr[0] + arr[n - 1];
        f = 1;

        for (i = 0; i < n / 2; i++) {
            if (arr[i] + arr[n - i - 1] != k) {
                f = 0;
            }
        }

        if (n > 3 && n % 2 == 1) {
            f = 0;
        }

        if (f == 1) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}