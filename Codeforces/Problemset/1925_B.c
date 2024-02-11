#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void solve()
{
    int x, n, i, balance = 1;

    scanf("%d %d", &x, &n);

    for (i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            if (n <= i) {
                balance = max(balance, x / i);
            }
            else if (n <= x / i) {
                balance = max(balance, i);
            }
        }
    }

    printf("%d\n", balance);
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