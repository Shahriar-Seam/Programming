#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, u, v;
    int a, b, c, max_deg = 0, min_deg = 1e9;

    cin >> n;

    vector <vector <int> > adj_list(n + 1);
    vector <int> degree(n + 1, 0);

    for (i = 1; i < n; i++) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

        degree[u]++;
        degree[v]++;
    }

    if (n <= 3) {
        cout << -1 << "\n";

        return;
    }

    a = b = c = 0;
    
    for (auto &it : adj_list) {
        sort(it.begin(), it.end(), [&] (int u, int v) {
            return degree[u] < degree[v];
        });
    }
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