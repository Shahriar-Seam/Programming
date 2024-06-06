#include <stdio.h>

void solve()
{
    int n, i;

    scanf("%d", &n);

    if (n % 2 == 0) {
        for (i = 1; i <= n; i += 2) {
            printf("%d %d ", i + 1, i);
        }
    }
    else {
        printf("%d ", n);

        for (i = 1; i < n; i++) {
            printf("%d ", i);
        }
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