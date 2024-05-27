#include <stdio.h>

void solve()
{
    int m, n;

    scanf("%d %d", &n, &m);

    if ((n >= m) && ((n % 2) == (m % 2))) {
        puts("YES");
    }
    else {
        puts("NO");
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