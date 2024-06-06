#include <stdio.h>
#include <stdlib.h>

int is_absent(int *arr, int len, int key)
{
    int i;

    for (i = 0; i < len; i++) {
        if (arr[i] == key) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int t, n, *arr, i, j, count;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        arr = (int *) calloc(n, sizeof(int));
        count = 0;

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);

            if (is_absent(arr, i, arr[i]) == 1) {
                count++;
            }
        }

        printf("%d\n", count);

        free(arr);
    }

    return 0;
}