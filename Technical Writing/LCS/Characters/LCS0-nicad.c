#include <stdio.h>
#include <string.h>

#define MAXN 50001

static unsigned short dp[2][MAXN];

int main(void) {
    static char a[MAXN], b[MAXN];

    scanf("%s %s", a, b);

    int m = strlen(a);
    int n = strlen(b);

    memset(dp[0], 0, (n + 1) * sizeof(unsigned short));

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
