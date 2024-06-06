#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int compare(const void *a, const void *b)
{
    return * (int *) a - * (int *) b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int n, i;
    int sum_all = 0, sum_low = 0, min_weight = INT_MAX;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);

        sum_all += arr[i];
    }

    qsort(arr, n, sizeof(int), compare);

    for (i = 0; i < n; i++) {
        sum_low += 
    }

    return 0;
}