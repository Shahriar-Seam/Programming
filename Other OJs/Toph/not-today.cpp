#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

void solve()
{
    int n, m, a, b, i;
    int u, v;

    cin >> n >> m >> a >> b;

    vector <vector <int> > adj_list(n + 1);
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <> > pq;
    vector <int> pop_count(n + 1, 0), dist(n + 1, inf);

    for (i = 0; i < m; i++) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    pq.push({0, b});
    pop_count[b] = 1;

    while (!pq.empty()) {
        auto [c, u] = pq.top();
        pq.pop();

        pop_count[u]++;

        if (pop_count[u] == 2) {
            dist[u] = c;

            if (u == a) {
                break;
            }

            for (auto &v : adj_list[u]) {
                pq.push({c + 1, v});
            }
        }
    }

    if (pop_count[a] == 2) {
        cout << dist[a] << "\n";
    }
    else {
        cout << -1 << "\n";
    }
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