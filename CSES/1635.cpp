#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7;

int num_ways(int x, vector <int> &v, vector <int> &dp)
{
    int i, j;

    for (i = 1; i <= x; i++) {
        for (j = 0; j < v.size(); j++) {
            if (i >= v[j]) {
                dp[i] = (dp[i] + dp[i - v[j]]) % mod;
            }
        }
    }

    return dp[x];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;

    cin >> n >> x;

    vector <int> v(n);
    vector <int> dp(x + 1, 0);
    // dp[i] = number of ways sum i can be constructed

    dp[0] = 1;

    for (auto &it : v) {
        cin >> it;
    }

    cout << num_ways(x, v, dp) << "\n";

    return 0;
}