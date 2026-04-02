#include <stdio.h>
#include <stdint.h>

void solve()
{
    int n, i, count = 0;

    scanf("%d", &n);

    int p[n + 1];

    for (i = 1; i <= n; i++) {
        scanf("%d", p + i);
    }

    for (i = 1; i <= n; i++) {
        if (p[i] <= i) {
            count++;
        }
    }

    printf("%d\n", count);
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