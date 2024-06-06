#include <stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

void solve()
{
    int n, a, b, ans = 1000000;

    scanf("%d %d %d", &n, &a, &b);

    ans = (n / 2) * b + (n - (n / 2) * 2) * a;

    printf("%d\n", min(n * a, ans));
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