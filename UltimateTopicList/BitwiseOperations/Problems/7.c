#include <stdio.h>

void solve()
{
    unsigned int n, new_n = 0, mask, mask2;

    scanf("%u", &n);

    for (mask = 0, mask2 = 31; (1 << mask) <= n; mask++, mask2--) {
        if (n & (1 << mask)) {
            new_n |= (1LL << mask2);
        }
    }

    printf("%u\n", new_n);
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