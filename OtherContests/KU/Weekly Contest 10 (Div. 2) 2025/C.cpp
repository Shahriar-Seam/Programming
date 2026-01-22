#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > adj_list;
vector <bool> visited;
int n, r, p, vis, _count;

void dfs(int u, int cnt)
{
    if (u == p) {
        vis++;

        _count = cnt;
    }
    else {
        visited[u] = true;

        for (int v : adj_list[u]) {
            if (!visited[v]) {
                dfs(v, cnt + 1);
            }
        }
    }
}

void solve()
{
    int i, u, v;

    cin >> n >> r >> p;

    vis = _count = 0;

    adj_list.assign(n + 1, vector <int> ());
    visited.assign(n + 1, false);

    for (i = 1; i < n; i++) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    dfs(r, -1);

    if (vis > 1) {
        cout << "0 1" << "\n";
    }
    else {
        if (_count % 2 == 0) {
            u = 1;
            v = 1;
        }
        else {
            u = _count;
            v = n - 2;
        }
        auto g = gcd(u, v);

        u /= g;
        v /= g;

        cout << u << " " << v << "\n";
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