#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, i, min_diff = 50000, min_ind = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (i = 1; i < n - 1; i++) {
        if (arr[i + 1] - arr[i - 1] < min_diff) {
            min_diff = arr[i + 1] - arr[i - 1];
            min_ind = i;
        }
    }

    min_diff = 0;

    for (i = 1; i < n; i++) {
        if (i != min_ind) {
            min_diff = max(min_diff, arr[i] - arr[i - 1]);
        }
        else {
            min_diff = max(min_diff, arr[i + 1] - arr[i - 1]);
        }
    }

    printf("%d\n", min_diff);

    return 0;
}