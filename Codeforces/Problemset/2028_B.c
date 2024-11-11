#include <stdio.h>

long long max(long long a, long long b)
{
    return a > b ? a : b;
}

void solve()
{
    long long n, b, c, ops = 0;

    scanf("%lld %lld %lld", &n, &b, &c);

    if (b == 0) {
        ops = ((c >= n) ? n : ((c >= n - 2) ? (n - 1) : -1));
    }
    else {
        ops = ((c >= n) ? n : (n - max(0, 1 + (n - c - 1) / b)));
    }

    printf("%lld\n", ops);
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