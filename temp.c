#include <stdio.h>

int main()
{
    int i, j, k, t, n = 13;

    int arr[20] = {50, 45, 60, 70, 56, 67, 78, 12, 34, 122, 233, 344, 566};

    for (i = 0; i < n - 1; i++) {
        k = i;

        for (j = i + 1; j < n; j++) {
            if ((i + 1) % 2 != 1 && arr[j] < arr[k]) {
                k = j;
            }

            if ((i + 1) % 2 == 1 && arr[j] > arr[k]) {
                k = j;
            }
        }

        t = arr[i];

        arr[i] = arr[k];

        arr[k] = t;
    }

    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
}