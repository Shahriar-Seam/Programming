#include <stdio.h>
#include <stdint.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

void solve()
{
    int n, i, j, models = 0;

    scanf("%d", &n);

    int s[n + 1], f[n + 1];

    for (i = 1; i <= n; i++) {
        scanf("%d", s + i);

        f[i] = 1;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j * j <= i; j++) {
            if (i % j == 0) {
                if (s[i] > s[j]) {
                    f[i] = max(f[i], f[j] + 1);
                }
                if (s[i] > s[i / j]) {
                    f[i] = max(f[i], f[i / j] + 1);
                }
            }
        }
    }

    for (i = 1; i <= n; i++) {
        models = max(models, f[i]);
    }

    printf("%d\n", models);
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