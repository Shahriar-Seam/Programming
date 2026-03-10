#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void solve()
{
    int n, i, j, a, k, f;
    int count[32] = {};

    scanf("%d", &n);

    for (j = 0; j < n; j++) {
        scanf("%d", &a);

        for (i = 0; i < 31; i++) {
            if (a & (1 << i)) {
                count[i]++;
            }
        }
    }

    for (k = 1; k <= n; k++) {
        f = 1;

        for (i = 0; i < 31; i++) {
            if (count[i] % k != 0) {
                f = 0;

                break;
            }
        }

        if (f) {
            printf("%d ", k);
        }
    }

    printf("\n");
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