#include <stdio.h>
#include <stdint.h>

#define int long long

int _min(int a, int b)
{
    return a < b ? a : b;
}

int _max(int a, int b)
{
    return a > b ? a : b;
}

int min_max(int n)
{
    int min = 10, max = 0;

    while (n > 0) {
        min = _min(min, n % 10);
        max = _max(max, n % 10);

        n /= 10;
    }

    return min * max;
}

void solve()
{
    int n, k, mm;

    scanf("%lld %lld", &n, &k);

    k--;

    while (k--) {
        mm = min_max(n);

        if (mm == 0) {
            break;
        }

        n += mm;
    }

    printf("%lld\n", n);
}

int32_t main()
{
    int t;

    scanf("%lld", &t);

    while (t--) {
        solve();
    }

    return 0;
}