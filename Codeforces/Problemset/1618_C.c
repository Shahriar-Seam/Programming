#include <stdio.h>

long long int GCD(long long int a, long long int b)
{
    return b == 0 ? a : GCD(b, a % b);
}

void solve()
{
    long long int n, temp, i, gcd_odd = 0, gcd_even = 0;
    long long int even = 1, odd = 1;

    scanf("%lld", &n);

    long long int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%lld", &temp);

        arr[i] = temp;

        if (i % 2 == 0) {
            gcd_even = GCD(gcd_even, temp);
        }
        else {
            gcd_odd = GCD(gcd_odd, temp);
        }
    }

    for (i = 0; i < n; i += 2) {
        if (arr[i] % gcd_odd == 0) {
            even = 0;
        }
    }

    for (i = 1; i < n; i += 2) {
        if (arr[i] % gcd_even == 0) {
            odd = 0;
        }
    }

    if (even == 1) {
        printf("%lld\n", gcd_odd);
    }
    else if (odd == 1) {
        printf("%lld\n", gcd_even);
    }
    else {
        puts("0");
    }
}

int main()
{
    int t;

    scanf("%d\n", &t);

    while (t--) {
        solve();
    }

    return 0;
}