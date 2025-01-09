#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;

    cin >> n;

    vector <int> v(n), dp(n, INT_MAX);

    for (auto &it : v) {
        cin >> it;
    }

    dp[0] = 0;
    dp[1] = abs(v[1] - v[0]);

    for (i = 2; i < n; i++) {
        dp[i] = min(dp[i - 1] + abs(v[i] - v[i - 1]), dp[i - 2] + abs(v[i] - v[i - 2]));
    }

    cout << dp[n - 1] << "\n";

    return 0;
}