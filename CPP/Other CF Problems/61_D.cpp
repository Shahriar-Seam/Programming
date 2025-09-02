#include <bits/stdc++.h>

using namespace std;

#define int long long

vector <bool> visited;
vector <vector <pair <int, int> > > adj_list;
vector <int> dist;

void dfs(int u, int cost)
{
    visited[u] = true;
    dist[u] = cost;

    for (auto &[v, c] : adj_list[u]) {
        if (!visited[v]) {
            dfs(v, cost + c);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, u, v, c, sum = 0;

    cin >> n;

    dist.assign(n + 1, 0);
    adj_list.assign(n + 1, vector <pair <int, int> > ());
    visited.assign(n + 1, false);

    for (i = 1; i < n; i++) {
        cin >> u >> v >> c;

        adj_list[u].push_back({v, c});
        adj_list[v].push_back({u, c});

        sum += 2 * c;
    }

    dfs(1, 0);

    cout << sum - *max_element(dist.begin(), dist.end()) << "\n";

    return 0;
}