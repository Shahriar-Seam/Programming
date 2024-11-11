#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

void solve()
{
    int l, r, k;

    scanf("%d %d %d", &l, &r, &k);

    printf("%d\n", max(0, (r / k) - l + 1));
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