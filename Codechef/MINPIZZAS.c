#include <stdio.h>

long long int GCD(long long int a, long long int b)
{
    return b == 0 ? a : GCD(b, a % b);
}

void solve()
{
    long long int n, k;

    scanf("%lld %lld", &n, &k);

    printf("%lld\n", (n * k / GCD(n, k)) / k);
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