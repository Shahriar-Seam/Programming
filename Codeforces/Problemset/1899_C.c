#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

void solve()
{
    int n, i, j, max_sum = INT_MIN, sum = 0;

    scanf("%d", &n);

    int a[n];

    for (i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    max_sum = sum = a[0];

    if (sum < 0) {
        sum = 0;
    }

    for (i = 1, j = 0; i < n; i++) {
        if (abs(a[i] % 2) != abs(a[i - 1] % 2)) {
            sum += a[i];
        }
        else {
            sum = a[i];
        }

        max_sum = max(max_sum, sum);

        if (sum < 0) {
            sum = 0;
        }
    }

    printf("%d\n", max_sum);
}

int32_t main()
{
    int32_t t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}