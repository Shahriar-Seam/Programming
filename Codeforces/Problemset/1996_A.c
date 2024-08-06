#include <stdio.h>

void solve()
{
    int n;

    scanf("%d", &n);

    printf("%d\n", (n + 2) / 4);
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