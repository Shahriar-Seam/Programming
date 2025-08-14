#include <stdio.h>
#include <stdint.h>

int32_t main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        int a, b, c, n, max = 0;

        scanf("%d %d %d %d", &a, &b, &c, &n);

        if (a > max) {
            max = a;
        }
        if (b > max) {
            max = b;
        }
        if (c > max) {
            max = c;
        }

        n -= max - a;
        n -= max - b;
        n -= max - c;

        if (n >= 0 && n % 3 == 0) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }

    return 0;
}