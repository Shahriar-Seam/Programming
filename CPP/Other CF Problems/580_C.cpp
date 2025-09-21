#include <bits/stdc++.h>

using namespace std;

void dfs(vector <vector <int> > &adj_list, vector <bool> &visited, vector <int> &a, vector <int> &deg, int u, int cats, int &count, int m)
{
    visited[u] = true;

    if (cats > m) {
        return;
    }

    if (deg[u] == 1 && u > 1) {
        count++;

        return;
    }

    for (auto &v : adj_list[u]) {
        if (!visited[v]) {
            if (a[v - 1]) {
                dfs(adj_list, visited, a, deg, v, cats + 1, count, m);
            }
            else {
                dfs(adj_list, visited, a, deg, v, 0, count, m);
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, u, v, count = 0;

    cin >> n >> m;

    vector <int> a(n), deg(n + 1);
    vector <bool> visited(n + 1, false);
    vector <vector <int> > adj_list(n + 1);

    for (auto &it : a) {
        cin >> it;
    }

    for (i = 1; i < n; i++) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (i = 1; i <= n; i++) {
        deg[i] = adj_list[i].size();
    }

    dfs(adj_list, visited, a, deg, 1, a[0], count, m);

    cout << count << "\n";

    return 0;
}