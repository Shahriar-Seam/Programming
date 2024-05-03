#include <stdio.h>

void solve()
{
    int n, i;

    scanf("%d", &n);

    printf("1 1\n1 2\n");

    for (i = 3; i <= n; i++) {
        printf("%d %d\n", i, i);
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