#include <stdio.h>
#include <stdlib.h>

int main() {
    int t, n, i;
    int *arr;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        arr = (int *) malloc(sizeof(int) * n);

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        for (i = 0; i < n / 2; i++) {
            printf("%d %d ", arr[i], arr[n - i - 1]);
        }

        if (n % 2 == 1) {
            printf("%d", arr[n / 2]);
        }

        printf("\n");

        free(arr);
    }

    return 0;
}