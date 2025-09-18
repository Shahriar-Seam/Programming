#include <bits/stdc++.h>

using namespace std;

void dfs(vector <vector <int> > &adj_list, vector <bool> &visited, vector <bool> &closed, int u)
{
    visited[u] = true;

    for (auto &v : adj_list[u]) {
        if (!visited[v] && !closed[v]) {
            dfs(adj_list, visited, closed, v);
        }
    }
}

int connected_components(vector <vector <int> > &adj_list, int n, vector <bool> &closed)
{
    int i, count = 0;
    vector <bool> visited(n + 1, false);

    for (i = 1; i <= n; i++) {
        if (!visited[i] && !closed[i]) {
            dfs(adj_list, visited, closed, i);

            count++;
        }
    }

    return count;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("closing.in", "r", stdin);
    freopen("closing.out", "w", stdout);

    int n, m, i, u, v;

    cin >> n >> m;

    vector <vector <int> > adj_list(n + 1);
    vector <bool> closed(n + 1, false);

    for (i = 0; i < m; i++) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (i = 0; i < n; i++) {
        cout << (connected_components(adj_list, n, closed) == 1 ? "YES" : "NO") << "\n";

        cin >> u;

        closed[u] = true;
    }

    return 0;
}