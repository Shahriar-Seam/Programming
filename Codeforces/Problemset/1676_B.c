#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, n, i, min, sum;
    int *arr;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        arr = (int *) malloc(sizeof(int) * n);
        min = 1000000000;
        sum = 0;

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);

            min = arr[i] < min ? arr[i] : min;
        }

        for (i = 0; i < n; i++) {
            sum += arr[i] - min;
        }

        printf("%d\n", sum);

        free(arr);
    }

    return 0;
}