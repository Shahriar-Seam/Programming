#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, f = 0;
    int u, v, c;

    cin >> n >> m;

    vector <vector <int> > edges(m, vector <int> (3, 0));
    vector <int> dist(n + 1, 0), parent(n + 1), cycle;

    for (auto &it : edges) {
        cin >> it[0] >> it[1] >> it[2];
    }

    for (i = 1; i < n; i++) {
        for (auto &it : edges) {
            u = it[0];
            v = it[1];
            c = it[2];

            if (dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;

                parent[v] = u;
            }
        }
    }

    for (auto &it : edges) {
        u = it[0];
        v = it[1];
        c = it[2];

        if (dist[u] + c < dist[v]) {
            f = 1;

            parent[v] = u;

            break;
        }
    }

    if (f) {
        cout << "YES\n";

        while (n--) {
            u = parent[u];
        }

        cycle.push_back(u);

        v = parent[u];

        while (v != u) {
            cycle.push_back(v);

            v = parent[v];
        }

        cycle.push_back(v);

        reverse(cycle.begin(), cycle.end());

        for (auto &it : cycle) {
            cout << it << " ";
        }

        cout << "\n";
    }
    else {
        cout << "NO\n";
    }

    return 0;
}