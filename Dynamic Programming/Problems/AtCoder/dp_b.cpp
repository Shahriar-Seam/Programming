#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, k;

    cin >> n >> k;

    vector <int> v(n), dp(n, INT_MAX);

    for (auto &it : v) {
        cin >> it;
    }

    dp[0] = 0;

    for (i = 1; i < n; i++) {
        for (j = 1; j <= k; j++) {
            if (i - j >= 0) {
                dp[i] = min(dp[i], dp[i - j] + abs(v[i] - v[i - j]));
            }
            else {
                break;
            }
        }
    }

    cout << dp[n - 1] << "\n";

    return 0;
}