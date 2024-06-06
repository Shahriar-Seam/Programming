#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (* (int *) a - * (int *) b);
}

int main()
{
    int n, *arr, i, f = 0, val;

    scanf("%d", &n);

    arr = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    for (i = 0; i < n; i++) {
        if (arr[i] > arr[0]) {
            f = 1;
            val = arr[i];
            break;
        }
    }

    f ? printf("%d", val) : printf("NO");

    return 0;
}