#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(15);

    int n, i, j;

    cin >> n;

    vector <double> v(n);
    vector <double> dp(n + 1, 0.0);

    for (auto &it : v) {
        cin >> it;
    }

    dp[0] = 1.0;

    for (i = 1; i <= n; i++) {
        for (j = i; j > 0; j--) {
            dp[j] = dp[j] * (1 - v[i - 1]) + dp[j - 1] * v[i - 1];
        }

        dp[0] = dp[0] * (1 - v[i - 1]);
    }

    cout << accumulate(dp.begin() + n / 2 + 1, dp.end(), 0.0) << "\n";

    return 0;
}