#include <stdio.h>
#include <stdlib.h>

int _max(int *arr, int n)
{
    int i, m = 0, c = 0;

    for (i = 0; i < n; i++) {
        if (arr[i] == 0) {
            c++;
        }
        else {
            if (c > m) {
                m = c;
            }

            c = 0;
        }
    }

    if (c > m) {
        m = c;
    }

    return m;
}

int main()
{
    int t, n, i, max;
    int *arr;

    scanf("%d", &t);

    while (t--) {
        scanf ("%d", &n);

        arr = (int *) malloc(sizeof(int) * n);

        for (i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        max = _max(arr, n);

        printf("%d\n", max);

        free(arr);
    }

    return 0;
}