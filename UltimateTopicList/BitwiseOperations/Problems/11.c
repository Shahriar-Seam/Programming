#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

int pops(int n)
{
    int i, count = 0;

    for (i = 0; (1 << i) <= n; i++) {
        if (n & (1 << i)) {
            count++;
        }

        if (count == 2) {
            return true;
        }
    }

    return false;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int n, l, r, x;
    int i, mask, difficulty, min_diff, max_diff;
    int count = 0;

    scanf("%d %d %d %d", &n, &l, &r, &x);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (mask = 0; mask < (1 << n); mask++) {
        difficulty = 0;
        min_diff = INT_MAX;
        max_diff = 0;

        for (i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                difficulty += arr[i];
                min_diff = min(min_diff, arr[i]);
                max_diff = max(max_diff, arr[i]);
            }
        }

        if (difficulty >= l && difficulty <= r && (max_diff - min_diff) >= x) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}