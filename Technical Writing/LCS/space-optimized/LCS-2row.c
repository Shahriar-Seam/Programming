/*
 * NiCad-style LCS for arrays of 16-bit unsigned integers.
 * Space-optimized: 2-row DP (baseline for comparison).
 * Input:  m n
 *         a[0] a[1] ... a[m-1]
 *         b[0] b[1] ... b[n-1]
 * Output: LCS length
 */
#pragma GCC optimize("O3,unroll-loops,inline")

#include <stdio.h>
#include <string.h>

#define MAXN 50001

static unsigned int dp[2][MAXN];
static unsigned short a[MAXN], b[MAXN];

int main(void) {
    int m, n;
    scanf("%d %d", &m, &n);

    for (int i = 0; i < m; i++) scanf("%hu", &a[i]);
    for (int j = 0; j < n; j++) scanf("%hu", &b[j]);

    memset(dp[0], 0, (n + 1) * sizeof(unsigned int));

    int bi;
    for (int i = 1; i <= m; i++) {
        bi = i & 1;
        dp[bi][0] = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[bi][j] = dp[1 - bi][j - 1] + 1;
            } else if (dp[1 - bi][j] >= dp[bi][j - 1]) {
                dp[bi][j] = dp[1 - bi][j];
            } else {
                dp[bi][j] = dp[bi][j - 1];
            }
        }
    }

    printf("%u\n", dp[bi][n]);
    return 0;
}
