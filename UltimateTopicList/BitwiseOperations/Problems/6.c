#include <stdio.h>

void solve()
{
    int n, even = 0, odd = 0, i, mask;

    scanf("%d", &n);

    for (mask = 0; (1 << mask) <= n; mask++) {
        if (mask & 1) {
            if (n & (1 << mask)) {
                odd |= (1 << mask);
            }
        }
        else {
            if (n & (1 << mask)) {
                even |= (1 << mask);
            }
        }
    }

    // It's been reversed
    odd >>= 1;
    even <<= 1;

    n = odd | even;

    printf("%d\n", n);
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}