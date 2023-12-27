#include <stdio.h>

int main()
{
    int t, n, a, b, c, d, f;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);

        f = 1;

        if (n * (a - b) > (c + d) || n * (a + b) < (c - d)) {
            f = 0;
        }

        puts(f ? "YES" : "NO");
    }

    return 0;
}