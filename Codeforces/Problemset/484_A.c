#include <stdio.h>
#include <stdint.h>

#define int long long

void solve()
{
    int l, r, x, i;

    scanf("%lld %lld", &l, &r);

    x = l;

    for (i = 0; i < 63; i++) {
        x |= (1LL << i);

        if (x > r) {
            x &= ~(1LL << i);
        }
    }

    printf("%lld\n", x);
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