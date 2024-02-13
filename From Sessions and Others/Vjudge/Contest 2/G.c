#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int main()
{
    int n, i, j, k, count = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            for (k = j + 1; k < n; k++) {
                if (arr[k] < (arr[i] + arr[j])) {
                    count++;
                }
                else {
                    break;
                }
            }
        }
    }

    printf("%d\n", count);

    return 0;
}