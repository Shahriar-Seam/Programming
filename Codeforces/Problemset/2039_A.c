#include <stdio.h>

void solve()
{
    int n, i;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("%d ", 2 * i + 1);
    }

    printf("\n");
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