#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, w, i, x, cost = 0, min_cost = 1e18;

    cin >> n >> w;

    vector <int> c(n), v(2 * w, 0LL);

    for (auto &it : c) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        v[i % (2 * w)] += c[i];
    }

    for (i = 0; i <= w; i++) {
        v.push_back(v[i]);
    }

    for (i = 0; i < w; i++) {
        cost += v[i];
    }

    min_cost = min(min_cost, cost);

    for (i = w; i < v.size(); i++) {
        cost += v[i] - v[i - w];

        min_cost = min(min_cost, cost);
    }

    cout << min_cost << "\n";
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