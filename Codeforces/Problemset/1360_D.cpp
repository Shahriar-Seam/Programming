#include <stdio.h>
#include <stdint.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

void get_divisors(int *divs, int n)
{
    int i, j = 0;

    for (i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs[j++] = i;
            divs[j++] = n / i;
        }
    }
}

void solve()
{
    int n, k, i, pack = 1e9;
    int divs[500] = {};

    scanf("%d %d", &n, &k);

    get_divisors(divs, n);

    for (i = 0; i < 500; i++) {
        if (divs[i] <= k && divs[i]) {
            pack = min(pack, n / divs[i]);
        }
    }

    printf("%d\n", pack);
}

int32_t main()
{
    int32_t t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}