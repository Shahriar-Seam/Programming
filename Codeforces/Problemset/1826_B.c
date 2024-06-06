#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b)
{
    return b == 0 ? a : GCD(b, a % b);
}

void solve()
{
    int n, i, gcd = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    for (i = 0; i < n / 2; i++) {
        gcd = GCD(gcd, abs(arr[i] - arr[n - i - 1]));
    }

    printf("%d\n", gcd);
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