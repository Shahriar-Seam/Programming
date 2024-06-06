#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return * (int *) a - * (int *) b;
}

int main()
{
    int n, i, j, count = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    qsort(arr, n, sizeof(int), compare);

    for (i = 0, j = 1; i < n; i++) {
        if (arr[i] >= j) {
            count++;

            j++;
        }
    }

    printf("%d\n", count);

    return 0;
}