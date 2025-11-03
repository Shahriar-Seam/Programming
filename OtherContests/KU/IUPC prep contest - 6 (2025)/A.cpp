#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > adj_list;
vector <bool> visited;
vector <int> cost;

int dfs(int u)
{
    int c = cost[u - 1];

    visited[u] = true;

    for (int v : adj_list[u]) {
        if (!visited[v]) {
            c = min(c, dfs(v));
        }
    }

    return c;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, u, v;
    long long gold = 0;

    cin >> n >> m;

    cost.assign(n, 0);
    adj_list.assign(n + 1, vector <int> ());
    visited.assign(n + 1, false);

    for (auto &it : cost) {
        cin >> it;
    }

    for (i = 0; i < m; i++) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            gold = gold + dfs(i);
        }
    }

    cout << gold << "\n";

    return 0;
}