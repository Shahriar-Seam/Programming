#include <stdio.h>
#include <stdint.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

void solve()
{
    int n, k, i, max_b = 0, exp = 0, sum = 0;

    scanf("%d %d", &n, &k);

    int a[n], b[n];

    for (i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", b + i);
    }

    for (i = 0; i < n; i++) {
        if (k == 0) {
            break;
        }

        sum += a[i];

        max_b = max(max_b, b[i]);

        exp = max(exp, sum + max_b * (k - 1));

        k--;
    }

    printf("%d\n", exp);
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