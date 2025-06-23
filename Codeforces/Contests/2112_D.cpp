#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, u, v;

    cin >> n;

    vector <vector <int> > adj_list(n + 1);
    set <pair <int, int> > edges;
    vector <int> degree(n + 1, 0), out(n + 1, 0), in(n + 1, 0);

    for (i = 1; i < n; i++) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (i = 1; i <= n; i++) {
        degree[i] = adj_list[i].size();
    }

    for (i = 1; i <= n; i++) {
        if (degree[i] == 2) {
            edges.insert({i, adj_list[i][0]});
            edges.insert({adj_list[i][1], i});

            out[adj_list[i][1]] = 1;
            out[i] = 1;

            in[i] = 1;
            in[adj_list[i][0]] = 1;

            auto node = adj_list[i][0];
            for (auto it : adj_list[node]) {
                if (edges.find({node, it}) == edges.end() && edges.find({it, node}) == edges.end()) {
                    edges.insert({it, node});

                    in[node] = 1;
                    out[it] = 1;
                }
            }

            break;
        }
    }

    if (edges.size() == 0) {
        cout << "NO\n";

        return;
    }

    for (i = 1; i <= n; i++) {
        for (auto it : adj_list[i]) {
            if (edges.find({i, it}) == edges.end() && edges.find({it, i}) == edges.end()) {
                if (out[it] == 1 && in[it] == 0) {
                    edges.insert({it, i});
                }
                else {
                    edges.insert({i, it});
                }
            }
        }
    }

    cout << "YES\n";

    for (auto it : edges) {
        cout << it.first << " " << it.second << "\n";
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