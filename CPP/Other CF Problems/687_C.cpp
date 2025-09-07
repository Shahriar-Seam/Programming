#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i, j, x, y;

    cin >> n >> k;

    vector <int> v;
    bool dp[n + 1][505][505] = {};
    // true if subset with sum k from subset with sum j using first i elements is possible

    dp[0][0][0] = 1;

    for (i = 1; i <= n; i++) {
        cin >> x;

        for (j = 0; j <= k; j++) {
            for (y = 0; y <= j; y++) {
                dp[i][j][y] = dp[i - 1][j][y];

                if (j >= x) {
                    dp[i][j][y] |= dp[i - 1][j - x][y];

                    if (y >= x) {
                        dp[i][j][y] |= dp[i - 1][j - x][y - x];
                    }
                }
            }
        }
    }

    for (i = 0; i <= k; i++) {
        if (dp[n][k][i]) {
            v.push_back(i);
        }
    }

    cout << v.size() << "\n";

    for (auto &it : v) {
        cout << it << " ";
    }

    cout << "\n";

    return 0;
}