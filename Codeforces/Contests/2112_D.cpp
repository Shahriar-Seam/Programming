#include <bits/stdc++.h>

using namespace std;

#define in 0
#define out 1

void dfs(int u, int d, vector <vector <int> > &adj_list, vector <bool> &visited)
{
    visited[u] = true;

    for (int v : adj_list[u]) {
        if (!visited[v]) {
            if (d == in) {
                cout << v << " " << u << "\n";
            }
            else {
                cout << u << " " << v << "\n";
            }

            dfs(v, d ^ 1, adj_list, visited);
        }
    }
}

void solve()
{
    int n, i, u, v;

    cin >> n;

    vector <vector <int> > adj_list(n + 1);
    vector <bool> visited(n + 1, false);

    for (i = 1; i < n; i++) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (i = 1; i <= n; i++) {
        if (adj_list[i].size() == 2) {
            cout << "YES\n";

            cout << i << " " << adj_list[i][0] << "\n";
            cout << adj_list[i][1] << " " << i << "\n";

            visited[i] = 1;

            dfs(adj_list[i][0], in, adj_list, visited);
            dfs(adj_list[i][1], out, adj_list, visited);

            return;
        }
    }

    cout << "NO\n";
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