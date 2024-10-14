#include <stdio.h>

long long max(long long a, long long b)
{
    return a > b ? a : b;
}

long long round_up(long long a, long long b)
{
    return a % b == 0 ? a / b : (a + b) / b;
}

void solve()
{
    long long n, x, i, temp, customers = 0;
    long long sum = 0;

    scanf("%lld %lld", &n, &x);

    for (i = 0; i < n; i++) {
        scanf("%lld", &temp);

        customers = max(customers, temp);

        sum += temp;
    }

    customers = max(customers, round_up(sum, x));

    printf("%lld\n", customers);
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