#include <stdio.h>
#include <math.h>

#define mod 1000000007LL

void solve()
{
    long long n, k, i;

    scanf("%lld %lld", &n, &k);

    long long fib[200005] = {};

    fib[0] = fib[1] = 1;

    for (i = 2; ; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % k;

        if (fib[i] == 0) {
            break;
        }
    }

    if (k == 1) {
        i = 0;
    }

    printf("%lld\n", ((n % mod) * ((i * 1LL) + 1)) % mod);
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