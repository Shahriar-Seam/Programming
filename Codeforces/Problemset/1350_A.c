#include <stdio.h>

int divisor(int n)
{
    int i;

    for (i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return i;
        }
    }

    return n;
}

int main()
{
    int t, n, k, d;

    scanf("%d", &t);

    while (t--) {
        scanf("%d %d", &n, &k);

        d = divisor(n);

        if (n % 2 == 0) {
            n = n + 2 * k;
        }
        else {
            n = n + d + 2 * (k - 1);
        }

        printf("%d\n", n);
    }

    return 0;
}