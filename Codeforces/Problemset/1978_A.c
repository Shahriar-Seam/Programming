#include <stdio.h>

int _max(int a, int b)
{
    return a > b ? a : b;
}

void solve()
{
    int n, i, max = 0, temp;

    scanf("%d", &n);

    for (i = 1; i < n; i++) {
        scanf("%d", &temp);

        max = _max(max, temp);
    }

    scanf("%d", &temp);

    printf("%d\n", max + temp);
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