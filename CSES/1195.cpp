#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18;

struct edge {
    int cost, city, state;

    bool operator > (const edge q) const {
        return cost > q.cost;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i;
    int u, v, c;
    priority_queue <edge, vector <edge>, greater <edge> > pq;

    cin >> n >> m;

    vector <vector <int> > dist(n + 1, vector <int> (2, inf));
    vector <vector <edge> > adj_list(n + 1);

    for (i = 0; i < m; i++) {
        cin >> u >> v >> c;

        adj_list[u].push_back({c, v, 0});
    }
    
    dist[1][0] = 0;

    pq.push({0, 1, 0});

    while (!pq.empty()) {
        auto [c, u, s] = pq.top();
        pq.pop();

        if (c > dist[u][s]) {
            continue;
        }

        for (auto &[c2, v, s2] : adj_list[u]) {
            if (dist[u][s] + c2 < dist[v][s]) {
                dist[v][s] = dist[u][s] + c2;

                pq.push({dist[v][s], v, s});
            }

            if (s == 0 && dist[u][0] + c2 / 2 < dist[v][1]) {
                dist[v][1] = dist[u][0] + c2 / 2;

                pq.push({dist[v][1], v, 1});
            }
        }
    }

    cout << dist[n][1] << "\n";

    return 0;
}