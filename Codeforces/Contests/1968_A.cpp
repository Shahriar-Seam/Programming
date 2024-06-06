#include <stdio.h>

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

void solve()
{
    int n, i, g, m = 1, y;

    scanf("%d", &n);

    for (i = n - 1; i >= 1; i--) {
        g = gcd(n, i);

        if (g + i > m) {
            m = g + i;
            y = i;
        }
    }

    printf("%d\n", y);
}

int main()
{
    int t;

    scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}