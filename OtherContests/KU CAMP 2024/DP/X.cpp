#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, i, j, k;

    cin >> a >> b;

    vector <vector <int> > dp(a + 1, vector <int> (b + 1, 1000000));
    // dp[i][j] = minimum number of moves to cut i x j into squares

    for (i = 1; i <= a; i++) {
        dp[i][1] = i - 1;
    }

    for (j = 1; j <= b; j++) {
        dp[1][j] = j - 1;
    }

    for (i = 1; i <= a; i++) {
        for (j = 1; j <= b; j++) {
            if (i == j) {
                dp[i][j] = 0;

                continue;
            }

            for (k = 1; k <= i / 2; k++) {
                dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i - k][j]);
            }

            for (k = 1; k <= j / 2; k++) {
                dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[i][j - k]);
            }
        }
    }

    cout << dp[a][b] << "\n";

    return 0;
}