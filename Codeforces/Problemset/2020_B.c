#include <stdio.h>
#include <stdint.h>
#include <limits.h>

long long square_root(long long n)
{
    long long l = 0, r = 2e9 + 5000, m, root = 1;

    while (l <= r) {
        m = (l + r) / 2;

        if (m * m <= n) {
            l = m + 1;
            root = m;
        }
        else {
            r = m - 1;
        }
    }

    return root;
}

void solve()
{
    long long k, n;
    long long l = 2, r = 4e18, m, root;

    scanf("%lld", &k);

    while (l <= r) {
        m = (l + r) / 2;
        root = square_root(m);

        if (m - root == k) {
            n = m;

            r = m - 1;
        }
        else if (m - root < k) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    printf("%lld\n", n);
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