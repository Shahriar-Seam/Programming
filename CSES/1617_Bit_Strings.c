#include <stdio.h>

#define mod 1000000007

int binary_exponentiation(long long int b, long long int p)
{
    long long int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (result * b) % mod;
        }

        b = (b * b) % mod;

        p /= 2;
    }

    return result % mod;
}

int main()
{
    int n;

    scanf("%d", &n);

    printf("%d\n", binary_exponentiation(2, n));

    return 0;
}