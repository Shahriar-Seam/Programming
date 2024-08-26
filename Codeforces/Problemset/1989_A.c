#include <stdio.h>

void solve()
{
    int x, y;

    scanf("%d %d", &x, &y);

    puts(y >= -1 ? "YES" : "NO");
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