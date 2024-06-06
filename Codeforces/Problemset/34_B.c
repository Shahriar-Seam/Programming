#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n, m, sum = 0, i;
    int *arr;

    scanf("%d %d", &n, &m);

    arr = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    for (i = 0; (arr[i] < 0) && (i < m); i++) {
        sum += arr[i];
    }

    printf("%d", abs(sum));

    free(arr);

    return 0;
}
