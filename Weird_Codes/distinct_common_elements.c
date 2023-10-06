#include <stdio.h>

int is_present(int *arr, int k, int l)
{
    int i;

    for (i = 0; i < l; i++) {
        if (arr[i] == k) {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int arr1[100] = {0}, arr2[100] = {0}, arr3[100] = {0};
    int i, j, k, m = 0;

    for (i = 0; i < 10; i++) {
        scanf("%d", &arr1[i]);
    }
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr2[i]);

        for (j = 0; j < 10; j++) {
            for (k = 0; k <= i; k++) {
                if (arr1[j] == arr2[k]) {
                    if (!is_present(arr3, arr1[j], m + 1)) {
                        arr3[m++] = arr1[j];
                        break;
                    }
                }
            }
        }
    }

    for (i = 0; i < m; i++) {
        printf("%d ", arr3[i]);
    }

    return 0;
}