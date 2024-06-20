#include <stdio.h>

int _gcd(int a, int b)
{
    return b == 0 ? a : _gcd(b, a % b);
}

void solve()
{
    int n, gcd = 0, i, gcd_count = 0;

    scanf("%d", &n);

    int arr[n];

    for (i = 0; i < n; i++) {
        scanf("%d", arr + i);

        gcd = _gcd(gcd, arr[i]);
    }

    for (i = 0; i < n; i++) {
        gcd_count += (arr[i] == gcd);
    }

    puts(gcd_count > 1 ? "NO" : "YES");
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