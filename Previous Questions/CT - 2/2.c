#include <stdio.h>

int is_absent(int *arr, int n, int m)
{
    int i;

    for (i = 0; i < m + 1; i++) {
        if (arr[i] == n) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int i, j, k, m = 0, count = 0, arr[100], arr2[100], n = 100;

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < j; k++) {
                if (arr[k] + arr[j] == arr[i]) {
                    if (is_absent(arr2, arr[i], m)) {
                        arr2[m++] = arr[i];
                    }
                }
            }
        }
    }

    printf("\nHere are the integers that can be obtained by adding 2 other integers from the given array:\n\n");

    for (i = 0; i < m; i++) {
        printf("%d ", arr2[i]);
    }

    printf("\n\nNumber of such integers = %d\n", m);

    return 0;
}