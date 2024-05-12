#include <stdio.h>

void solve()
{
    int p;

    scanf("%d", &p);

    printf("%d %d\n", 2, p - 1);
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