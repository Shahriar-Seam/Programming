#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i;

    cin >> n >> k;

    vector <int> v(n);
    vector <bool> dp(k + 1);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i <= k; i++) {
        for (auto &it : v) {
            if (i - it >= 0 && !dp[i - it]) {
                dp[i] = true;

                break;
            }
        }
    }

    cout << (dp[k] ? "First" : "Second") << "\n";

    return 0;
}