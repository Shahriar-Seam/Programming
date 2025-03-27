#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define int long long int

int max(int a, int b)
{
    return a > b ? a : b;
}

bool possible(int arr[], int m, int x, int n)
{
    int water = 0, i;

    for (i = 0; i < n; i++) {
        water += max(0, m - arr[i]);
    }

    return water <= x;
}

void solve()
{
    int n, x, i;
    int l = 1, r = 2e9, m, h = 0;

    scanf("%lld %lld", &n, &x);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%lld", arr + i);
    }

    while (l <= r) {
        m = (l + r) / 2;

        if (possible(arr, m, x, n)) {
            h = m;

            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    printf("%lld\n", h);
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