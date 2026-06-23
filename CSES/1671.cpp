#include <bits/stdc++.h>

using namespace std;

struct edge {
    int v;
    long long c;

    edge() : v(0), c(0) {}

    edge(int v, long long c) : v(v), c(c) {}
};

class compare {
public:
    bool operator() (edge &a, edge &b) const {
        return a.c > b.c;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i;
    long long inf = 1e18 + 5;
    int u, v;
    long long c;
    priority_queue <edge, vector <edge>, compare> pq;

    cin >> n >> m;

    vector <vector <edge> > adj_list(n + 1);
    vector <long long> cost(n + 1, inf);

    for (i = 0; i < m; i++) {
        cin >> u >> v >> c;

        adj_list[u].push_back(edge(v, c));
    }

    pq.push(edge(1, 0));
    cost[1] = 0;

    while (!pq.empty()) {
        auto e = pq.top();
        pq.pop();

        v = e.v;
        c = e.c;

        if (c > cost[v]) {
            continue;
        }

        for (auto &e : adj_list[v]) {
            if (cost[v] + e.c < cost[e.v]) {
                cost[e.v] = cost[v] + e.c;

                pq.push(edge(e.v, cost[e.v]));
            }
        }
    }

    for (i = 1; i <= n; i++) {
        cout << cost[i] << " ";
    }

    cout << "\n";

    return 0;
}