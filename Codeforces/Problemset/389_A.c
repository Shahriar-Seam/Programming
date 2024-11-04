#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return * (int *) a - * (int *) b;
}

int first(int *arr, int n)
{
    int i;

    for (i = 0; i < n; i++) {
        if (arr[i] > 0) {
            return arr[i];
        }
    }

    return 0;
}

int main()
{
    int n, i, j, min;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }
    
    for (j = 0; j < 50; j++) {
        qsort(arr, n, sizeof(int), compare);

        min = first(arr, n);

        for (i = 1; i < n; i++) {
            if (arr[i] > min) {
                arr[i] -= min;
            }
        }
    }

    printf("%d\n", first(arr, n) * n);

    return 0;
}