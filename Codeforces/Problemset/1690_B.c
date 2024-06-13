#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

void solve()
{
    int n, i, m = 0, f = 1;

    scanf("%d", &n);

    int a[n], b[n];

    for (i = 0; i < n; i++) {
        scanf("%d", a + i);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", b + i);
    }

    for (i = 0; i < n; i++) {
        m = max(m, a[i] - b[i]);
    }

    for (i = 0; i < n; i++) {
        if (b[i] != 0 && (a[i] - b[i]) < m) {
            f = 0;

            break;
        }
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