#include <stdio.h>

int bin_exp(int b, int p, int m)
{
    int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (1LL * result * b) % m;
        }

        b = (1LL * b * b) % m;

        p >>= 1;
    }

    return result % m;
}

int main()
{
    int n, a, b;

    scanf("%d", &n);

    while (n--) {
        scanf("%d %d", &a, &b);

        printf("%d\n", bin_exp(a, b, (int) 1e9 + 7));
    }

    return 0;
}