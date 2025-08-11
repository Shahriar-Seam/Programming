#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > adj_list;
vector <bool> visited;
vector <int> parent, path;
int f = 0;

void dfs(int u, int sz)
{
    visited[u] = true;

    for (int v : adj_list[u]) {
        if (v != parent[u] && visited[v] && sz > 1 && !f) {
            path.push_back(v);

            int temp = u;

            while (temp != v) {
                path.push_back(temp);

                temp = parent[temp];
            }

            path.push_back(temp);

            f = 1;
        }

        if (!visited[v]) {
            parent[v] = u;

            dfs(v, sz + 1);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, u, v;

    cin >> n >> m;

    adj_list.resize(n + 1);
    visited.assign(n + 1, false);
    parent.assign(n + 1, -1);

    for (i = 0; i < m; i++) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (i = 1; i <= n; i++) {
        dfs(i, 1);
    }

    if (path.empty()) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        cout << path.size() << "\n";

        for (auto &it : path) {
            cout << it << " ";
        }

        cout << "\n";
    }

    return 0;
}