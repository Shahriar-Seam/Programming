#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j;

    cin >> n;

    vector <int> v(n);
    vector <bool> dp(100005, false);
    // dp[i] = true if i can be made using some money

    dp[0] = true;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        for (j = dp.size() - 1; j >= v[i]; j--) {
            dp[j] = dp[j] | dp[j - v[i]];
        }
    }

    cout << accumulate(dp.begin(), dp.end(), 0) - 1 << "\n";

    for (i = 1; i < dp.size(); i++) {
        if (dp[i]) {
            cout << i << " ";
        }
    }

    cout << "\n";

    return 0;
}