#include <stdio.h>

void solve()
{
    int n, k;

    scanf("%d %d", &n, &k);

    printf("%d\n", n * k - k + 1);
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