#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    int n, m, i, j;
    int l, r, left = 1000, right = -1, size = 0;
    int u = -1, d;

    scanf("%d %d", &n, &m);

    char sheet[n][m + 1];

    for (i = 0; i < n; i++) {
        scanf(" %s", sheet[i]);

        l = 1000;
        r = -1;

        for (j = 0; j < m; j++) {
            if (l == 1000 && sheet[i][j] == '*') {
                l = j;
            }
            if (sheet[i][j] == '*') {
                r = j;

                d = i;
            }

            if (u == -1 && sheet[i][j] == '*') {
                u = i;
            }
        }

        left = min(left, l);
        right = max(right, r);
    }

    size = right - left + 1;

    char masterpiece[d - u + 1][size + 1];

    for (i = u; i <= d; i++) {
        for (j = left; j < left + size; j++) {
            masterpiece[i - u][j - left] = sheet[i][j];
        }

        masterpiece[i - u][j - left] = '\0';
    }

    for (i = 0; i < d - u + 1; i++) {
        puts(masterpiece[i]);
    }

    return 0;
}