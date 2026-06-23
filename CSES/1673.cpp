#include <bits/stdc++.h>

using namespace std;

#define int long long

struct edge {
    int a, b, c;

    edge() : a(0), b(0), c(0 ) {}

    edge(int a, int b, int c) : a(a), b(b), c(c) {}
};

void bellman_ford(vector <edge> &v, vector <vector <int> > &cost, int n)
{
    int i;

    for (i = 1; i < n; i++) {
        for (auto &[a, b, c] : v) {
            cost[1][b] = min(cost[1][b], cost[1][a] + c);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, inf = 1e18;
    int a, b, c, min_cost;

    cin >> n >> m;

    vector <edge> v(m);
    vector <vector <int> > cost(n + 1, vector <int> (n + 1, inf));

    for (i = 1; i <= n; i++) {
        cost[i][i] = 0;
    }

    for (i = 0; i < m; i++) {
        cin >> a >> b >> c;

        v[i] = edge(a, b, -c);
    }

    bellman_ford(v, cost, n);
    
    min_cost = cost[1][n];
    
    bellman_ford(v, cost, n);

    if (cost[1][n] < min_cost) {
        cout << "-1\n";
    }
    else {
        cout << -min_cost << "\n";
    }

    return 0;
}