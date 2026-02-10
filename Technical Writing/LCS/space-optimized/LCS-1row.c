/*
 * Single-array space-optimized LCS for arrays of 16-bit unsigned integers.
 * Uses ONE 1-D array + a single temp variable for the diagonal.
 *
 * Classic trick: iterate left-to-right, save dp[j-1] (the "old diagonal")
 * in a temp before it's overwritten.
 *
 * Memory: dp[n+1]  (one row, not two)
 *
 * Input:  m n
 *         a[0] a[1] ... a[m-1]
 *         b[0] b[1] ... b[n-1]
 * Output: LCS length
 */
#pragma GCC optimize("O3,unroll-loops,inline")

#include <stdio.h>
#include <string.h>

#define MAXN 50001

static unsigned int dp[MAXN];       /* single row */
static unsigned short a[MAXN], b[MAXN];

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++) scanf("%hu", &a[i]);
    for (int j = 0; j < n; j++) scanf("%hu", &b[j]);

    memset(dp, 0, (n + 1) * sizeof(unsigned int));

    for (int i = 1; i <= m; i++) {
        unsigned int prev = 0;          /* dp[i-1][j-1] — the diagonal */
        for (int j = 1; j <= n; j++) {
            unsigned int tmp = dp[j];   /* save dp[i-1][j] before overwrite */
            if (a[i - 1] == b[j - 1]) {
                dp[j] = prev + 1;
            } else if (tmp >= dp[j - 1]) {
                dp[j] = tmp;            /* keep dp[i-1][j] (already there) */
            } else {
                dp[j] = dp[j - 1];
            }
            prev = tmp;                 /* old dp[i-1][j] becomes diagonal for j+1 */
        }
    }

    printf("%u\n", dp[n]);
    return 0;
}
