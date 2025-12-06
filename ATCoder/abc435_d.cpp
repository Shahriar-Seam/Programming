#include <bits/stdc++.h>

using namespace std;

const int sz = 3e5 + 5;
vector <vector <int> > adj_list;
bitset <sz> visited;

void dfs(int &u)
{
    visited[u] = 1;

    for (int &v : adj_list[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, q, u, v, t;

    cin >> n >> m;

    adj_list.assign(n + 1, vector <int> ());

    while (m--) {
        cin >> u >> v;

        adj_list[v].push_back(u);
    }

    cin >> q;

    while (q--) {
        cin >> t >> v;

        if (t == 1) {
            if (!visited[v]) {
                dfs(v);
            }
        }
        else {
            if (visited[v]) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
    }

    return 0;
}