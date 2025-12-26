#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j;

    cin >> n >> m;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        it %= m;
    }

    if (n > m) {
        cout << "YES\n";
    }
    else {
        vector <vector <bool> > dp(n, vector <bool> (m + 1, false));
        // dp[i][j] = possible to achieve sum j (mod m) using number i

        dp[0][0] = true;
        dp[0][v[0]] = true;

        for (i = 1; i < n; i++) {
            dp[i] = dp[i - 1];
            vector <bool> marked(m + 1, false);

            for (j = m; j >= 0; j--) {
                if (dp[i][j] && !marked[j]) {
                    if (!dp[i][((j + v[i]) % m == 0) ? m : (j + v[i]) % m]) {
                        marked[((j + v[i]) % m == 0) ? m : (j + v[i]) % m] = true;
                    }

                    dp[i][((j + v[i]) % m == 0) ? m : (j + v[i]) % m] = true;
                }
            }
        }

        cout << (dp[n - 1][m] || count(v.begin(), v.end(), 0) ? "YES" : "NO") << "\n";
    }

    return 0;
}