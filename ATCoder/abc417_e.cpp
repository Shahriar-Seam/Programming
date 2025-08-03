#include <bits/stdc++.h>

using namespace std;

void dfs(int x, int y, vector <vector <int> > &adj_list, vector <bool> &visited, vector <int> &path) {
    visited[x] = true;
    path.push_back(x);
    
    if (x == y) {
        for (auto p : path) {
            cout << p << " ";
        }

        return;
    }
    
    for (int v : adj_list[x]) {
        if (!visited[v]) {
            dfs(v, y, adj_list, visited, path);

            if (visited[y]) {
                return;
            }
        }
    }
    
    path.pop_back();
}

void solve()
{
    int n, m, x, y, i, u, v;

    cin >> n >> m >> x >> y;

    vector <vector <int> > adj_list(n + 1);
    vector <bool> visited(n + 1, false);
    vector <int> path;

    for (i = 0; i < m; i++) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (auto &it : adj_list) {
        sort(it.begin(), it.end());
    }

    dfs(x, y, adj_list, visited, path);

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