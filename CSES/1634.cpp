#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 7;

int min_coins(int x, vector <int> &v, vector <int> &dp)
{
    int i, j;

    for (i = 1; i <= x; i++) {
        for (j = 0; j < v.size(); j++) {
            if (i >= v[j]) {
                dp[i] = min(dp[i], dp[i - v[j]] + 1);
            }
        }
    }

    return dp[x] == inf ? -1 : dp[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;

    cin >> n >> x;

    vector <int> v(n);
    vector <int> dp(x + 1, inf);
    // dp[i] = minimum number of coins needed to produce sum i

    dp[0] = 0;

    for (auto &it : v) {
        cin >> it;
    }

    cout << min_coins(x, v, dp) << "\n";

    return 0;
}