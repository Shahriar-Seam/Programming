#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (* (int *) a - * (int *) b);
}

int main()
{
    int n, k, i;
    int *arr;

    scanf("%d %d", &n, &k);

    arr = (int *) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    if (k == 0) {
        if (arr[0] <= 1) {
            printf("-1");
        }
        else {
            printf("1");
        }
    }
    else if (arr[k - 1] == arr[k]) {
        printf("-1");
    }
    else {
        printf("%d", arr[k - 1]);
    }

    free(arr);

    return 0;
}