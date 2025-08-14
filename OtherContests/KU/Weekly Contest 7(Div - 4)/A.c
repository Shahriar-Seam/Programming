#include <stdio.h>
#include <stdint.h>

int32_t main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        int x, y, n, k;

        scanf("%d %d %d", &x, &y, &n);

        k = (n / x) * x + y;

        if (k > n) {
            k -= x;
        }

        printf("%d\n", k);
    }

    return 0;
}