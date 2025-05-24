#include <bits/stdc++.h>

using namespace std;

#define int long long

void dfs(int s, vector <int> &b, vector <vector <pair <int, int> > > &adj_list, vector <bool> &visited, int batteries, int mid)
{
    visited[s] = true;
    batteries += b[s];

    for (auto t : adj_list[s]) {
        if (!visited[t.first] && t.second <= mid && batteries >= t.second) {
            dfs(t.first, b, adj_list, visited, batteries, mid);
        }
    }
}

void solve(int tc)
{
    int n, m, s, t, c, i;

    cin >> n >> m;

    vector <int> b(n + 1, 0);
    vector <vector <pair <int, int> > > adj_list(n + 1);

    for (i = 1; i <= n; i++) {
        cin >> b[i];
    }

    for (i = 0; i < m; i++) {
        cin >> s >> t >> c;

        adj_list[s].push_back({t, c});
    }

    int l = 1, r = 2e9, mid;
    int max_edge_cost = -1;

    while (l <= r) {
        mid = (l + r) / 2;

        vector <bool> visited(n + 1, false);

        dfs(1, b, adj_list, visited, 0, mid);

        if (visited[n]) {
            max_edge_cost = mid;

            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    for (mid = 100; mid >= 1; mid--) {
        vector <bool> visited(n + 1, false);

        dfs(1, b, adj_list, visited, 0, mid);

        if (visited[n]) {
            max_edge_cost = mid;
        }
    }

    cout << max_edge_cost << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve(i);
    }

    return 0;
}