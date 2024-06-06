#include <stdio.h>

long long int GCD (long long int a, long long int b)
{
    return b == 0 ? a : GCD(b, a % b);
}

int main()
{
    long long int n, i, gcd = 0;
    long long int product = 1, ans = 1;

    scanf("%lld", &n);

    long long int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%lld", arr + i);

        gcd = GCD(gcd, arr[i]);
    }

    for (i = 0; i < n; i++) {
        product *= arr[i] % 1000000007;

        product %= 1000000007;
    }

    for (i = 0; i < gcd; i++) {
        ans = ans * product;

        ans = ans % 1000000007;
    }

    ans = ans % 1000000007;

    printf("%lld", ans);

    return 0;
}