#include <stdio.h>

void solve()
{
    long long int l, r, n, s;

    scanf("%lld %lld", &l, &r);

    n = r - l;

    s = 2 * n + 1;

    printf("%d\n", s);
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