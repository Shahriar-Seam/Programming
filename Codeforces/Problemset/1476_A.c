#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

void solve()
{
    int n, k, val = 0;

    scanf("%d %d", &n, &k);

    if (n > k) {
        k = (n / k + (n % k != 0)) * k;
    }

    val = k / n + (k % n != 0);

    printf("%d\n", val);
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