#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, i, index, min, sum;
    int *arr;

    scanf("%d %d", &n, &k);

    arr = (int *)malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    min = sum = 0;
    index = 0;

    for (i = 0; i < k; i++) {
        sum += arr[i];
    }

    min = sum;

    for (i = k; i < n; i++) {
        sum += arr[i] - arr[i - k];
        if (sum < min) {
            min = sum;
            index = i - k + 1;
        }
    }

    printf("%d", index + 1);

    free(arr);

    return 0;
}
