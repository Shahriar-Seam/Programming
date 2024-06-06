#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (* (int *) b - * (int *) a);
}

int main()
{
    int t, n, *arr, *arr2, i, m1, m2;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        arr = (int *) malloc(sizeof(int) * n);
        arr2 = (int *) malloc(sizeof(int) * n);

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);

            arr2[i] = arr[i];
        }

        qsort(arr2, n, sizeof(int), compare);

        m1 = arr2[0];
        m2 = arr2[1];

        for (i = 0; i < n; i++) {
            if (arr[i] == m1) {
                printf("%d ", arr[i] - m2);
            }
            else {
                printf("%d ", arr[i] - m1);
            }
        }

        printf("\n");

        free(arr);
        free(arr2);
    }

    return 0;
}