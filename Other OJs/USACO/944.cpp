#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e9;

struct pt {
    int x, y;
};

void dfs(vector <vector <int> > &adj_list, vector <bool> &visited, vector <pt> &v_p, int u, pt &p_ma, pt &p_mi)
{
    visited[u] = true;

    p_ma.x = max(p_ma.x, v_p[u - 1].x);
    p_ma.y = max(p_ma.y, v_p[u - 1].y);

    p_mi.x = min(p_mi.x, v_p[u - 1].x);
    p_mi.y = min(p_mi.y, v_p[u - 1].y);

    for (auto &v : adj_list[u]) {
        if (!visited[v]) {
            dfs(adj_list, visited, v_p, v, p_ma, p_mi);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream cin("fenceplan.in");
    ofstream cout("fenceplan.out");

    int n, m, i, u, v;
    pt p_ma, p_mi;
    int min_p = inf * 2;

    cin >> n >> m;

    vector <pt> v_p(n);
    vector <vector <int> > adj_list(n + 1);
    vector <bool> visited(n + 1, false);

    for (auto &it : v_p) {
        cin >> it.x >> it.y;
    }

    for (i = 0; i < m; i++) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            p_ma = {0, 0};
            p_mi = {inf, inf};

            dfs(adj_list, visited, v_p, i, p_ma, p_mi);

            min_p = min(min_p, 2 * (p_ma.x - p_mi.x) + 2 * (p_ma.y - p_mi.y));
        }
    }

    cout << min_p << "\n";

    return 0;
}