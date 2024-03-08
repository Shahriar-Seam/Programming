#include <stdio.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

void solve()
{
    int a, b, count = 0;

    scanf("%d %d", &a, &b);

    count = min(min(a, b), (a + b) / 3);

    printf("%d\n", count);
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