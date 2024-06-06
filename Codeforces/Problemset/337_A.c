#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int _min(int *arr, int n, int m)
{
    int min = 1000000000, diff, i;

    for (i = 0; i <= m - n; i++) {
        diff = arr[i + n - 1] - arr[i];

        if (diff < min) {
            min = diff;
        }
    }

    if (min == 1000000000) {
        return 0;
    }

    return min;
}

int main()
{
    int n, m, i;
    int *arr;
    
    scanf("%d %d", &n, &m);

    arr = (int *) malloc(sizeof(int) * m);

    for (i = 0; i < m; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, m, sizeof(int), compare);

    printf("%d", _min(arr, n, m));

    return 0;
}