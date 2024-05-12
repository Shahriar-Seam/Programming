// Write a recursive solution to find the
// second maximum number from a given set of integers.

#include <stdio.h>
#include <limits.h>

void recurse(int n, int *arr, int *max, int *s_max, int i)
{
    if (i == n) {
        return;
    }

    if (arr[i] >= *max) {
        *s_max = *max;
        *max = arr[i];
    }

    recurse(n, arr, max, s_max, i + 1);
}

int main()
{
    int n, arr[100], i;
    int max = INT_MIN, s_max = INT_MIN;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    recurse(n, arr, &max, &s_max, 0);

    printf("%d\n", s_max);

    return 0;
}