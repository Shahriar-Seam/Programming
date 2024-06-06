#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, k, i, count = 0;
    int *arr;

    scanf("%d %d", &n, &k);

    arr = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    k = 5 - k;

    for (i = 0; i < n; i++) {
        if (arr[i] <= k) {
            count++;
        }
    }

    printf("%d", count / 3);

    return 0;
}