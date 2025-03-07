#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7;

int num_ways(int n)
{
    int i, j;

    vector <int> dp = {1};
    // stores the last 6 states
    // dp[n] = sum _i = n - 1 to n - 6

    for (i = 1; i <= n; i++) {
        dp.push_back(accumulate(dp.begin(), dp.end(), 0LL) % mod);

        if (dp.size() > 6) {
            dp.erase(dp.begin());
        }
    }

    return dp.back();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    cout << num_ways(n) << "\n";

    return 0;
}