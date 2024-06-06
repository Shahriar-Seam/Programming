#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n, i, min_cost, max_cost;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (i == 0) {
            min_cost = abs(arr[i + 1] - arr[i]);
            max_cost = abs(arr[n - 1] - arr[i]);
        }
        else if (i == n - 1) {
            min_cost = abs(arr[i - 1] - arr[i]);
            max_cost = abs(arr[0] - arr[i]);
        }
        else {
            min_cost = min(abs(arr[i + 1] - arr[i]), abs(arr[i - 1] - arr[i]));
            max_cost = max(abs(arr[n - 1] - arr[i]), abs(arr[0] - arr[i]));
        }

        printf("%d %d\n", min_cost, max_cost);
    }

    return 0;
}