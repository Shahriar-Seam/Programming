#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, l, r, len;

    cin >> n;

    vector <int> v(n), pref(n + 1, 0);
    vector <vector <int> > dp(n, vector <int> (n, 0));

    for (i = 0; i < n; i++) {
        cin >> v[i];

        pref[i + 1] = pref[i] + v[i];
    }

    for (len = 1; len <= n; len++) {
        for (l = 0, r = l + len - 1; r < n; l++, r++) {
            if (len == 1) {
                dp[l][r] = v[l];
            }
            else {
                dp[l][r] = pref[r + 1] - pref[l] - min(dp[l + 1][r], dp[l][r - 1]);
            }
        }
    }

    cout << dp[0][n - 1] << "\n";

    return 0;
}