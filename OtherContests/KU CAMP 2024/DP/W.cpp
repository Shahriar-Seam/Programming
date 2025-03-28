#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    int n, m, i, j;

    cin >> s >> t;

    n = s.size();
    m = t.size();

    vector <vector <int> > dp(n + 1, vector <int> (m + 1, 0));
    // dp[i][j] = edit distance between first i characters of s and j characters of t

    for (i = 0; i <= n; i++) {
        dp[i][0] = i;
    }

    for (j = 0; j <= m; j++) {
        dp[0][j] = j;
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (s[i - 1] == t[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }

            dp[i][j] = min({dp[i][j], 1 + dp[i - 1][j], 1 + dp[i][j - 1]});
        }
    }

    cout << dp[n][m] << "\n";

    return 0;
}