#include <stdio.h>
#include <stdint.h>

#define int long long
const int mod = 1e9 + 7;

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int binary_exponentiation(int b, int p)
{
    int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (result * b) % mod;
        }

        b = (b * b) % mod;

        p >>= 1;
    }

    return result;
}

int32_t main()
{
    int n, x, i, num = 0, denom = 0, max_p = 0, sum = 0;

    scanf("%lld %lld", &n, &x);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%lld", arr + i);

        denom = max(denom, arr[i]);

        sum += arr[i];
    }

    for (i = 0; i < n; i++) {
        if (denom - arr[i] == 0) {
            num += 1;
        }
        
        max_p = min(max_p, denom - arr[i]);
    }

    while (num > 0) {
        if (num % x == 0) {
            num /= x;
            max_p++;
        }
        else {
            break;
        }
    }

    printf("%lld\n", (binary_exponentiation(x, max_p + sum - denom)) % mod);

    return 0;
}