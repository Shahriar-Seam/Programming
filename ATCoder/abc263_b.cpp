#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;

    cin >> n;

    vector <int> p(n), dp(n, 0);

    for (auto &it : p) {
        cin >> it;
    }

    for (i = 2; i <= n; i++) {
        dp[i - 1] = dp[p[i - 2] - 1] + 1;
    }

    cout << dp[n - 1] << "\n";

    return 0;
}