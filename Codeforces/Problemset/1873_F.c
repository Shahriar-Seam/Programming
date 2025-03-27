#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define int long long

int max(int a, int b)
{
    return a > b ? a : b;
}

void solve()
{
    int n, k, i, j, max_len = 0, sum = 0;

    scanf("%lld %lld", &n, &k);

    int a[n], h[n];

    for (i = 0; i < n; i++) {
        scanf("%lld", a + i);

        if (a[i] <= k) {
            max_len = 1;
        }
    }

    for (i = 0; i < n; i++) {
        scanf("%lld", h + i);
    }

    sum = a[0];

    if (sum > k) {
        sum = 0;
        j = 1;
    }
    else {
        j = 0;
    }

    for (i = 1; i < n; i++) {
        if (h[i - 1] % h[i] == 0) {
            sum += a[i];
        }
        else {
            j = i;
            sum = a[i];
        }

        if (sum > k) {
            max_len = max(max_len, i - j);
            
            while (sum > k) {
                sum -= a[j++];
            }
        }
        else {
            max_len = max(max_len, i - j + 1);
        }

    }

    printf("%lld\n", max_len);
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