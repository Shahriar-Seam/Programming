#include <bits/stdc++.h>

using namespace std;

void dfs(int u, int n, vector <vector <int> > &adj_list, vector <bool> visited, vector <int> &path, int &f)
{
    visited[u] = true;

    if (u == n) {
        f = 1;

        return;
    }

    for (int v : adj_list[u]) {
        if (!visited[v]) {
            path.push_back(v);

            dfs(v, n, adj_list, visited, path, f);

            if (!f) {
                path.pop_back();
            }
        }
    }
}

void solve()
{
    int n, i, u, v, f = 0;

    cin >> n;

    vector <vector <int> > adj_list(n + 1, vector <int> ());
    vector <bool> visited(n + 1, false);
    vector <int> path;
    vector <pair <int, int> > ops;

    for (i = 1; i < n; i++) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    path.push_back(1);

    dfs(1, n, adj_list, visited, path, f);

    visited.assign(n + 1, false);

    for (auto &it : path) {
        visited[it] = true;
    }

    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            ops.push_back({2, i});
        }
    }

    path.pop_back();

    for (auto &it : path) {
        ops.push_back({1, 0});

        ops.push_back({2, it});
    }

    cout << ops.size() << "\n";

    for (auto &it : ops) {
        cout << it.first << " ";

        if (it.second != 0) {
            cout << it.second;
        }

        cout << "\n";
    }

    cout << "\n";
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