#include <stdio.h>
#include <stdlib.h>

int comp_func(const void *a, const void *b)
{
    return (*(int *) a - *(int *) b);
}

int min_value(int *arr, int n)
{
    int i, diff, min = arr[1] - arr[0];

    for (i = 2; i < n; i++) {
        diff = arr[i] - arr[i - 1];

        if (diff < min) {
            min = diff;
        }
    }

    return min;
}

int main()
{
    int t, n, i;
    int *arr;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        arr = (int *) malloc(sizeof(int) * n);

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        qsort(arr, n, sizeof(int), comp_func);

        printf("%d\n", min_value(arr, n));
        
        free(arr);
    }

    return 0;
}