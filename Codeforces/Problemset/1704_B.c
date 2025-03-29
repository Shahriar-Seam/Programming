#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define int long long

int min(int a, int b)
{
    return a < b ? a : b;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

void solve()
{
    int n, x, i, low, high, count = 0;

    scanf("%lld %lld", &n, &x);

    int a[n];

    for (i = 0; i < n; i++) {
        scanf("%lld", a + i);
    }

    low = a[0] - x;
    high = a[0] + x;

    for (i = 1; i < n; i++) {
        if (a[i] >= high) {
            if (a[i] - x <= high) {
                low = max(low, a[i] - x);
            }
            else {
                low = a[i] - x;
                high = a[i] + x;

                count++;
            }
        }
        else if (a[i] <= low) {
            if (a[i] + x >= low) {
                high = min(high, a[i] + x);
            }
            else {
                low = a[i] - x;
                high = a[i] + x;

                count++;
            }
        }
        else {
            low = max(low, a[i] - x);
            high = min(high, a[i] + x);
        }
    }

    printf("%lld\n", count);
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