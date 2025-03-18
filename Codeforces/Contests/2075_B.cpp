#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, k, i, cost = 0;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    if (k != 1) {
        sort(v.begin(), v.end(), greater <int> ());

        for (i = 0; i <= k; i++) {
            cost += v[i];
        }
    }
    else {
        for (i = 1; i < n - 1; i++) {
            cost = max(cost, v[i]);
        }

        cost = max({cost + v[0], cost + v[n - 1], v[0] + v[n - 1]});
    }

    cout << cost << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}