#include <stdio.h>

long long max(long long a, long long b)
{
    return a > b ? a : b;
}

void solve()
{
    long long n, i, temp;
    long long count = 0;

    scanf("%lld", &n);

    for (i = 1; i <= n; i++) {
        scanf("%lld", &temp);

        count += max(0, temp - i - count);
    }

    printf("%lld\n", count);
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