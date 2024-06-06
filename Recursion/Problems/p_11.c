// Write a recursive solution to find the
// maximum element from an array.

#include <stdio.h>
#include <limits.h>

void _max(int *arr, int i, int *max, int n)
{
    if (i == n) {
        return;
    }
    else if (arr[i] > *max) {
        *max = arr[i];
    }

    _max(arr, i + 1, max, n);
}

int main()
{
    int arr[100], n, i, max = INT_MIN;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    _max(arr, 0, &max, n);

    printf("%d\n", max);

    return 0;
}