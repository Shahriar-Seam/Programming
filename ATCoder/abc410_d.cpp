#include <bits/stdc++.h>

using namespace std;

#define int long long

vector <vector <pair <int, int> > > adj_list;
vector <bool> visited;
vector <int> min_xor, basis;

void dfs(int u)
{
    visited[u] = true;

    for (auto it : adj_list[u]) {
        int v = it.first;
        int w = it.second;

        if (!visited[v]) {
            min_xor[v] = min_xor[u] ^ w;
            
            dfs(v);
        }
        else {
            int temp = min_xor[u] ^ min_xor[v] ^ w;

            for (auto jt : basis) {
                temp = min(temp, temp ^ jt);
            }

            if (temp > 0) {
                basis.push_back(temp);
            }

            min_xor[v] = min(min_xor[v], temp);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i;
    int u, v, w;

    cin >> n >> m;

    adj_list.assign(n + 1, vector <pair <int, int> > ());
    min_xor.assign(n + 1, 0);
    visited.assign(n + 1, false);

    for (i = 0; i < m; i++) {
        cin >> u >> v >> w;

        adj_list[u].push_back({v, w});
    }

    visited[1] = true;
    dfs(1);

    if (visited[n]) {
        for (auto it : basis) {
            min_xor[n] = min(min_xor[n], min_xor[n] ^ it);
        }

        cout << min_xor[n] << "\n";
    }
    else {
        cout << -1 << "\n";
    }

    return 0;
}