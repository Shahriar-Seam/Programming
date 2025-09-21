#include <bits/stdc++.h>

using namespace std;

void dfs(vector <vector <int> > &adj_list, vector <bool> &visited, int u)
{
    visited[u] = true;

    for (auto &v : adj_list[u]) {
        if (!visited[v]) {
            dfs(adj_list, visited, v);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, u, v;

    cin >> n >> m;

    vector <vector <int> > adj_list_f(n + 1), adj_list_b(n + 1);
    vector <bool> visited(n + 1, false);

    for (i = 0; i < m; i++) {
        cin >> u >> v;

        adj_list_f[u].push_back(v);
        adj_list_b[v].push_back(u);
    }

    dfs(adj_list_f, visited, 1);

    for (i = 2; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO\n";

            cout << 1 << " " << i << "\n";

            exit(0);
        }
    }

    visited.assign(n + 1, false);

    dfs(adj_list_b, visited, 1);

    for (i = 2; i <= n; i++) {
        if (!visited[i]) {
            cout << "NO\n";

            cout << i << " " << 1 << "\n";

            exit(0);
        }
    }

    cout << "YES\n";

    return 0;
}