#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (* (int *) a - * (int *) b);
}

int _min(int n, int min_i, int max_i)
{
    int a[4], min, max;

    max = max_i > min_i ? max_i : min_i;
    min = max_i < min_i ? max_i : min_i;

    a[0] = max + 1;
    a[1] = n - min;
    a[2] = n - max_i + min_i + 1;
    a[3] = n - min_i + max_i + 1;

    qsort(a, 4, sizeof(int), compare);

    return a[0];
}

int main()
{
    int t, n, *arr, i, max, max_i, min, min_i, min_moves;

    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        arr = (int *) malloc(sizeof(int) * n);

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        max = min = arr[0];
        max_i = min_i = 0;

        for (i = 0; i < n; i++) {
            if (arr[i] > max) {
                max = arr[i];
                max_i = i;
            }
            else if (arr[i] < min) {
                min = arr[i];
                min_i = i;
            }
        }

        min_moves = _min(n, min_i, max_i);

        printf("%d\n", min_moves);

        free(arr);
    }

    return 0;
}