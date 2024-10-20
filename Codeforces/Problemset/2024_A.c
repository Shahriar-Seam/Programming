#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

void solve()
{
    int a, b;

    scanf("%d %d", &a, &b);

    printf("%d\n", min(max(0, 2 * a - b), a));
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