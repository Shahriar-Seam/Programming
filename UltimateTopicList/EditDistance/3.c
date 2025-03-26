#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int main()
{
    char s[105], t[105];
    int n, m, i, j;
    char c, d;

    scanf("%s %s", s, t);

    n = strlen(s);
    m = strlen(t);

    int dp[n + 1][m + 1];
    // dp[i][j] = levenshtein distance between first i characters of s and first j characters of t

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= m; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
            }
            else if (i == 0) {
                dp[i][j] = dp[i][j - 1] + t[j - 1] - 'a' + 1;
            }
            else if (j == 0) {
                dp[i][j] = dp[i - 1][j] + s[i - 1] - 'a' + 1;
            }
            else {
                dp[i][j] = 1e8;
            }
        }
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            c = s[i - 1] - 'a' + 1;
            d = t[j - 1] - 'a' + 1;

            if (c == d) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = abs(c - d) + dp[i - 1][j - 1];
            }

            dp[i][j] = min(dp[i][j], c + dp[i - 1][j]);
            dp[i][j] = min(dp[i][j], d + dp[i][j - 1]);
        }
    }

    printf("%d\n", dp[n][m]);

    return 0;
}