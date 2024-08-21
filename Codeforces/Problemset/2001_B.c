#include <stdio.h>

void solve()
{
    int n, i;

    scanf("%d", &n);

    if (n % 2 == 0) {
        printf("-1");
    }
    else {
        for (n; n > 1; n -= 2) {
            printf("%d %d ", n - 1, n);
        }

        printf("%d", n);
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