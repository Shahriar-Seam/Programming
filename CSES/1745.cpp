#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j;

    cin >> n;

    vector <int> v(n);
    
    for (auto &it : v) {
        cin >> it;
    }

    vector <bool> dp(accumulate(v.begin(), v.end(), 0) + 1, false);
    // dp[i] = is it possible to make sum i
    dp[0] = true;

    for (i = 0; i < n; i++) {
        for (j = dp.size() - 1; j >= 0; j--) {
            if (j >= v[i]) {
                dp[j] = dp[j] | dp[j - v[i]];
            }
        }
    }

    cout << accumulate(dp.begin(), dp.end(), -1) << "\n";

    for (i = 1; i < dp.size(); i++) {
        if (dp[i]) {
            cout << i << " ";
        }
    }

    return 0;
}