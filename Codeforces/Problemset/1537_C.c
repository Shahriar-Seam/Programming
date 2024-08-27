#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return * (int *) a - * (int *) b;
}

void solve()
{
    int n, i, index = -1, min_diff = INT_MAX;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    qsort(arr, n, sizeof(int), compare);

    if (n == 2) {
        printf("%d %d\n", arr[0], arr[1]);
    }
    else {
        for (i = 1; i < n; i++) {
            if (arr[i] - arr[i - 1] < min_diff) {
                index = i;
                min_diff = arr[i] - arr[i - 1];
            }
        }

        for (i = index; i < n; i++) {
            printf("%d ", arr[i]);
        }

        for (i = 0; i < index; i++) {
            printf("%d ", arr[i]);
        }

        printf("\n");
    }
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}