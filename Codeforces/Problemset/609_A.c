#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (* (int *) b - * (int *) a);
}

int main()
{
    int n, m, i, sum = 0;
    int *arr;

    scanf("%d %d", &n, &m);

    arr = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    for (i = 0; sum < m; i++) {
        sum += arr[i];
    }

    printf("%d", i);

    return 0;
}