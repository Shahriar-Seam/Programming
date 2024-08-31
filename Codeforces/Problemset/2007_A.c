#include <stdio.h>

void solve()
{
    int l, r, i, count = 0;

    scanf("%d %d", &l, &r);

    for (i = l; i <= r; i++) {
        count += i % 2;
    }

    printf("%d\n", count / 2);
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