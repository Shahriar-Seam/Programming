// https://cses.fi/problemset/task/1158/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int max(int a, int b)
{
    return a > b ? a : b;
}

int knapsack(int x, int n, int *h, int *s, int *dp)
{
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = x; j >= h[i]; j--) {
            dp[j] = max(dp[j], s[i] + dp[j - h[i]]);
        }
    }

    return dp[x];
}

int32_t main()
{
    int n, x, i;

    scanf("%d %d", &n, &x);

    int h[n], s[n];
    int *dp = (int *) calloc(x + 1, sizeof(int));

    for (i = 0; i < n; i++) {
        scanf("%d", h + i);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", s + i);
    }

    printf("%d\n", knapsack(x, n, h, s, dp));

    return 0;
}