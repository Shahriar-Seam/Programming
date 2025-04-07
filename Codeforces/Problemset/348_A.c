#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define int long long

int max(int a, int b)
{
    return a > b ? a : b;
}

bool possible(int arr[], int n, int m)
{
    int supervise = 0, i;

    for (i = 0; i < n; i++) {
        supervise += m - arr[i];
    }

    return supervise >= m;
}

int32_t main()
{
    int n, i;
    int l = 0, r = 1e12, m, rounds = 0;

    scanf("%lld", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%lld", arr + i);

        l = max(l, arr[i]);
    }

    while (l <= r) {
        m = (l + r) / 2;

        if (possible(arr, n, m)) {
            rounds = m;

            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    printf("%lld\n", rounds);

    return 0;
}