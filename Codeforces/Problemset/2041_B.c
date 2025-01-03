#include <stdio.h>
#include <stdint.h>

#define int long long

#define sum(n) (n * (n + 1)) / 2

int possible(int w, int b, int m)
{
    return w + b >= sum(m);
}

void solve()
{
    int w, b;
    int l = 0, r = 1e9 + 5, m;

    scanf("%lld %lld", &w, &b);

    while (l <= r) {
        m = l + (r - l) / 2;
        
        if (possible(w, b, m)) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    printf("%lld\n", l - 1);
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