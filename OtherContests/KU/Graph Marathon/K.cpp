#include <bits/stdc++.h>

using namespace std;

#define int long long

vector <vector <int> > adj_list;
vector <int> visited, time_in, low, sub_size;
int max_pairs, n;

void dfs(int u, int t, int p)
{
    sub_size[u] = 1;
    visited[u] = true;
    low[u] = time_in[u] = t;

    for (int v : adj_list[u]) {
        if (!visited[v]) {
            dfs(v, t + 1, u);

            sub_size[u] += sub_size[v];

            if (low[v] > time_in[u]) {
                auto x = sub_size[v];

                max_pairs = min(max_pairs, ((n - x) * (n - x - 1)) / 2 + (x * (x - 1)) / 2);
            }
        }

        if (v != p) {
            low[u] = min(low[u], low[v]);
        }
    }
}

void solve()
{
    int m, i, u, v;

    cin >> n >> m;

    adj_list.assign(n + 1, vector <int> ());
    visited.assign(n + 1, 0);
    time_in.assign(n + 1, 0);
    low.assign(n + 1, 0);
    sub_size.assign(n + 1, 0);

    max_pairs = (n * (n - 1)) / 2;

    for (i = 0; i < m; i++) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    dfs(1, 1, 0);

    cout << max_pairs << "\n";
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