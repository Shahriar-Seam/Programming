#include <stdio.h>
#include <stdint.h>

#define int long long

#define sz (int) 2e5 + 5
const int mod = 1e9 + 7;
int f[sz] = {};

void factorial()
{
    int i;

    f[0] = 1;

    for (i = 1; i < sz; i++) {
        f[i] = (f[i - 1] * i) % mod;
    }
}

// ax + by = gcd(a, b)
// returns gcd(a, b) and calculates x and y
int extended_euclid(int a, int b, int *x, int *y)
{
    if (b == 0) {
        *x = 1;
        *y = 0;

        return a;
    }

    int x1, y1;
    int d = extended_euclid(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - y1 * (a / b);

    return d;
}

// x = a^-1 (mod m)
int inverse_modulo(int a, int m)
{
    int x, y;
    int g = extended_euclid(a, m, &x, &y);

    if (g != 1) {
        return -1;
    }

    return (x % m + m) % m;
}

int nCr(int n, int r)
{
    return ((((f[n] * inverse_modulo(f[r], mod)) % mod) * inverse_modulo(f[n - r], mod)) % mod + mod) % mod;
}

int32_t main()
{
    factorial();

    int n, count;

    scanf("%lld", &n);

    count = ((2 * nCr(2 * n - 1, n) - n) % mod + mod) % mod;

    printf("%lld\n", count);

    return 0;
}