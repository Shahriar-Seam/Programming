#include <stdio.h>

long long int _min(long long int a, long long int b)
{
    return (a < b) ? a : b;
}

long long int _max(long long int a, long long int b)
{
    return (a > b) ? a : b;
}

long long int main()
{
    long long int t, n, m, x, y;

    scanf("%lld", &t);

    while (t--) {
        scanf("%lld %lld", &n, &m);
        scanf("%lld %lld", &x, &y);

        printf("%lld\n", _max(n - x, m - y) * _min(n, m));
    }

    return 0;
}