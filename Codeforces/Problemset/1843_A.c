#include <stdio.h>
#include <stdlib.h>

int compare (const void *a, const void *b)
{
    return (* (int *) b - * (int *) a);
}

int main()
{
    int t, n, sum, i, j;
    int *arr;

    scanf ("%d", &t);

    while (t--) {
        scanf ("%d", &n);

        arr = (int *) malloc(sizeof(int) * n);
        sum = 0;

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        qsort(arr, n, sizeof(int), compare);

        for (i = 0, j = n - 1; i < n / 2; i++, j--) {
            sum += arr[i] - arr[j];
        }

        printf("%d\n", sum);

        free(arr);
    }

    return 0;
}