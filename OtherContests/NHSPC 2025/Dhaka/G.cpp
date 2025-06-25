#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, k;
    int i, j, l;

    cin >> n >> m >> k;

    vector <int> v(m);
    vector <bool> dp(n + 1, false);

    dp[0] = true;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < m; i++) {
        if (dp[n]) {
            break;
        }
        
        for (j = n; j > 0; j--) {
            for (l = 1; l <= k; l++) {
                if (dp[j]) {
                    break;
                }

                if (j - l * v[i] >= 0) {
                    dp[j] = dp[j - l * v[i]];
                }
                else {
                    break;
                }
            }
        }
    }

    cout << (dp[n] ? "YES" : "NO") << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}