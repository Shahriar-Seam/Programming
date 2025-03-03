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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, u, v, c, num_edges = 0, min_cost = 0;

    cin >> n >> m;

    adj_list.resize(n + 1);
    visited.resize(n + 1, false);
    multiset <pair <int, pair <int, int> > > edges;
    vector <pair <pair <int, int>, int> > mst;

    for (i = 0; i < m; i++) {
        cin >> u >> v >> c;

        edges.insert({c, {u, v}});
    }

    while (num_edges < n - 1) {
        auto it = *edges.begin();
        edges.erase(edges.begin());

        c = it.first;
        u = it.second.first;
        v = it.second.second;

        visited.resize(n + 1, false);

        dfs(u);

        if (!visited[v]) {
            min_cost += c;
            num_edges++;

            adj_list[u].push_back(v);
            adj_list[v].push_back(u);

            mst.push_back({{u, v}, c});
        }
    }

    cout << min_cost << "\n";

    for (auto it : mst) {
        cout << it.first.first << " " << it.first.second << " " << it.second << "\n";
    }

    return 0;
}