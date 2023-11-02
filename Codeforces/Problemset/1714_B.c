#include <stdio.h>
#include <stdlib.h>

int is_distinct(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int t, n, *arr;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        arr = (int *)malloc(sizeof(int) * n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int count = 0;
        while (!is_distinct(arr, n)) {
            n--;
            count++;
        }

        printf("%d\n", count);
        free(arr);
    }

    return 0;
}