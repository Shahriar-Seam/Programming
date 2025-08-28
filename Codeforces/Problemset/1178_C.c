#include <stdio.h>
#include <stdint.h>

#define int long long

const int m = 998244353;

int bin_exp(int b, int p)
{
    int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (result * b) % m;
        }

        b = (b * b) % m;

        p >>= 1;
    }

    return result % m;
}

int32_t main()
{
    int w, h;

    scanf("%lld %lld", &w, &h);

    printf("%lld", bin_exp(2, w + h));

    return 0;
}