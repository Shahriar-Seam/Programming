#include <stdio.h>
#include <stdlib.h>

int is_absent(int *arr2, int len, int k)
{
    int i;

    for (i = 0; i < len; i++) {
        if (arr2[i] == k) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int t, n, i, j;
    int *arr, *arr2;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        arr = (int *) malloc(sizeof(int) * 2 * n);
        arr2 = (int *) calloc(2 * n, sizeof(int));

        for (i = 0, j = 0; i < 2 * n; i++) {
            scanf("%d", &arr[i]);

            if (is_absent(arr2, j + 1, arr[i]) == 1) {
                arr2[j++] = arr[i];
            }
        }

        for (i = 0; i < j; i++) {
            printf("%d ", arr2[i]);
        }

        printf("\n");

        free(arr);
        free(arr2);
    }

    return 0;
}
