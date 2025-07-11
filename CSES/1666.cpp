#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > adj_list;
vector <bool> visited;

void dfs(int u)
{
    visited[u] = true;

    for (int v : adj_list[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i;
    int u, v;
    vector <pair <int, int> > roads;

    cin >> n >> m;

    adj_list.assign(n + 1, vector <int> ());
    visited.assign(n + 1, false);

    while (m--) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    dfs(1);

    for (i = 1; i <= n; i++) {
        if (i > 1 && !visited[i]) {
            roads.push_back({1, i});

            adj_list[i].push_back(1);
            adj_list[1].push_back(i);

            dfs(i);
        }
    }

    cout << roads.size() << "\n";

    for (auto &it : roads) {
        cout << it.first << " " << it.second << "\n";
    }

    return 0;
}