#include <stdio.h>
#include <stdint.h>

void solve()
{
    int n, x, m, l, r, L, R;

    scanf("%d %d %d", &n, &x, &m);

    L = R = x;

    while (m--) {
        scanf("%d %d", &l, &r);

        if (l < L && r >= L) {
            L = l;
        }

        if (r > R && l <= R) {
            R = r;
        }
    }

    printf("%d\n", R - L + 1);
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