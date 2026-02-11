#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, u, v, x, y, p = 1, i;

    cin >> n;

    vector <vector <int> > adj_list(n + 1);
    vector <int> degree(n + 1, 0), nodes(n, 0);
    queue <int> q;

    for (i = 1; i < n; i++) {
        cin >> u >> v >> x >> y;

        if (x > y) {
            swap(u, v);
        }

        adj_list[u].push_back(v);

        degree[v]++;
    }

    for (i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        u = q.front();
        q.pop();

        nodes[u - 1] = p++;

        for (auto &v : adj_list[u]) {
            if (!--degree[v]) {
                q.push(v);
            }
        }
    }

    for (auto &it : nodes) {
        cout << it << " ";
    }

    cout << "\n";
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