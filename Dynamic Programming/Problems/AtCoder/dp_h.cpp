#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j;

    cin >> n >> m;

    vector <string> v(n);
    vector <vector <int> > dp(n, vector <int> (m, 0));

    for (auto &it : v) {
        cin >> it;
    }

    dp[0][0] = (v[0][0] == '#') ? 0 : 1;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (v[i][j] == '#') {
                dp[i][j] = 0;

                continue;
            }
            else if (i == 0 && j == 0) {
                continue;
            }

            if (i == 0) {
                dp[i][j] = dp[i][j - 1];
            }
            else if (j == 0) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }
    }

    cout << dp[n - 1][m - 1] << "\n";

    return 0;
}