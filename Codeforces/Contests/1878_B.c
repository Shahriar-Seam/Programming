#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, n, i;
    int *arr;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        arr = (int *) calloc(2 * n, sizeof(int));

        

        for (i = 0; i < 2 * n; i++) {
            if (i % 2 == 1) {
                arr[i] = i;
            }
        }

        for (i = 0; i < 2 * n; i++) {
            if (i % 2 != 0) {
                printf("%d ", arr[i]);
            }
        }

        printf("\n");

        free(arr);
    }

    return 0;
}