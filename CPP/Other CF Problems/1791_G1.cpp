#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, c, i;

    cin >> n >> c;

    vector <int> v(n), cost;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        cost.push_back(v[i] + i + 1);
    }

    sort(cost.begin(), cost.end());

    for (i = 0; i < n; i++) {
        c -= cost[i];

        if (c < 0) {
            break;
        }
    }

    cout << i << "\n";
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