#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e18;

struct edge {
    int cost, city;

    bool operator > (const edge q) const {
        return cost > q.cost;
    }
};

void print(priority_queue <int> &pq)
{
    if (pq.empty()) {
        return;
    }

    auto top = pq.top();
    pq.pop();

    print(pq);

    cout << top << " ";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k, i;
    int u, v, c;
    priority_queue <edge, vector <edge>, greater <edge> > pq;

    cin >> n >> m >> k;

    vector <priority_queue <int> > dist(n + 1);
    vector <vector <edge> > adj_list(n + 1);

    for (i = 0; i < m; i++) {
        cin >> u >> v >> c;

        adj_list[u].push_back({c, v});
    }
    
    dist[1].push(0);

    pq.push({0, 1});

    while (!pq.empty()) {
        auto [c, u] = pq.top();
        pq.pop();

        if (dist[u].size() == k && c > dist[u].top()) {
            continue;
        }

        for (auto &[c2, v] : adj_list[u]) {
            if (dist[v].size() < k) {
                dist[v].push(c + c2);

                pq.push({c + c2, v});
            }
            else if (dist[v].top() > c + c2) {
                dist[v].pop();
                dist[v].push(c + c2);

                pq.push({c + c2, v});
            }
        }
    }

    print(dist[n]);

    return 0;
}