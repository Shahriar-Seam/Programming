#include <stdio.h>

#define Anonymous_HF __(a, n, i, m, a, t, e)
#define __(n, e, u, t, r, a, l) t##r##u##e

long long int min(long long int a, long long int b)
{
    return a < b ? a : b;
}

long long int GCD(long long int a, long long int b)
{
    return b == 0 ? a : GCD(b, a % b);
}

Anonymous_HF ()
{
    long long int a, b, x, y, gcd;

    scanf("%lld %lld %lld %lld", &a, &b, &x, &y);

    gcd = GCD(x, y);

    x /= gcd;
    y /= gcd;

    printf("%lld", min(a / x, b / y));
}