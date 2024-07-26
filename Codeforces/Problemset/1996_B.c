#include <stdio.h>

void solve()
{
    int n, k, i, j;

    scanf("%d %d", &n, &k);
    getchar();

    char grid[n][n];

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            grid[i][j] = getchar();
        }

        getchar();
    }

    for (i = 0; i < n; i += k) {
        for (j = 0; j < n; j += k) {
            putchar(grid[i][j]);
        }

        puts("");
    }
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