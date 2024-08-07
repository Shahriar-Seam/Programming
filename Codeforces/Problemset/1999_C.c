#include <stdio.h>

void solve()
{
    int n, s, m;
    int i, l, r = 0, f = 0;

    scanf("%d %d %d", &n, &s, &m);

    for (i = 0; i < n; i++) {
        scanf("%d", &l);

        if (l - r >= s) {
            f = 1;
        }

        scanf("%d", &r);
    }

    if (m - r >= s) {
        f = 1;
    }

    puts(f == 1 ? "YES" : "NO");
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