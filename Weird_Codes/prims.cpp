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

    int n, m, i, u, v, c, num_edges = 0, min_cost = 0, source = 1;

    cin >> n >> m;

    adj_list.resize(n + 1);
    visited.resize(n + 1, false);
    multiset <pair <int, pair <int, int> > > edges;
    vector <pair <pair <int, int>, int> > mst;
    vector <multiset <pair <int, int> > > not_mst(n + 1);

    for (i = 0; i < m; i++) {
        cin >> u >> v >> c;

        edges.insert({c, {u, v}});
        not_mst[u].insert({c, v});
        not_mst[v].insert({c, u});
    }    

    while (num_edges < n - 1) {
        auto it = not_mst[source].begin();
        
        c = it->first;
        u = source;
        v = it->second;

        not_mst[source].erase(not_mst[source].begin());

        visited.resize(n + 1, false);

        dfs(u);

        if (!visited[v]) {
            min_cost += c;
            num_edges++;

            adj_list[u].push_back(v);
            adj_list[v].push_back(u);

            mst.push_back({{u, v}, c});
        }

        for (auto s : mst) {
            if (not_mst[s.first.first].begin()->first < not_mst[source].begin()->first) {
                source = s.first.first;
            }

            if (not_mst[s.first.second].begin()->first < not_mst[source].begin()->first) {
                source = s.first.second;
            }
        }
    }

    cout << min_cost << "\n";

    for (auto it : mst) {
        cout << it.first.first << " " << it.first.second << " " << it.second << "\n";
    }

    return 0;
}