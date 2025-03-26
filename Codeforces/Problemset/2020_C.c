#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define int long long

void solve()
{
    int a = 0, b, c, d, i;
    bool p, q, r, f = true;

    scanf("%lld %lld %lld", &b, &c, &d);

    for (i = 0; i < 62; i++) {
        p = b & (1LL << i);
        q = c & (1LL << i);
        r = d & (1LL << i);

        if ((!p && !q && r) || (p && !q && r) || (p && q && !r)) {
            a |= (1LL << i);
        }
        else if ((!p && q && r) || (p && !q && !r)) {
            f = false;
        }
    }

    if (f) {
        printf("%lld\n", a);
    }
    else {
        printf("-1\n");
    }
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