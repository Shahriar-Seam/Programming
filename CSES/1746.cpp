#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j, num_arrays = 0;

    cin >> n >> m;

    vector <int> v(n);
    vector <vector <int> > dp(n + 1, vector <int> (m + 1, 0));
    // dp[i][j] = no of prefixes of length i that
    // can be formed such that the last element
    // is j

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 1; i <= m; i++) {
        if (v[0] == i || v[0] == 0) {
            dp[1][i] = 1;
        }
    }

    for (i = 2; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (v[i - 1] != 0 && v[i - 1] != j) {
                dp[i][j] = 0;

                continue;
            }

            if (j - 1 >= 1) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
            }

            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            
            if (j + 1 <= m) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
            }
        }
    }

    for (i = 1; i <= m; i++) {
        num_arrays = (num_arrays + dp[n][i]) % mod;
    }

    cout << num_arrays << "\n";

    return 0;
}