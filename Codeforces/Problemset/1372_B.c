#include <stdio.h>

int smallest_factor(int n)
{
    int i;

    for (i = 3; i * i <= n; i += 2) {
        if (n % i == 0) {
            return i;
        }
    }

    return n;
}

void solve()
{
    int n, i, p;

    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("%d %d\n", n / 2, n / 2);
    }
    else {
        p = smallest_factor(n);

        p = n / p;

        printf("%d %d\n", p, n - p);
    }
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