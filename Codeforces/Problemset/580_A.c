#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, count = 0, max = 0;
    int *arr;

    scanf("%d", &n);

    arr = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (i > 0 && arr[i - 1] <= arr[i]) {
            count++;
        }
        else {
            if (count > max) {
                max = count;
            }

            count = 1;
        }
    }

    if (count > max) {
        max = count;
    }

    printf("%d", max);

    free(arr);

    return 0;
}