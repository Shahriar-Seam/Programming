#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > adj_list;
vector <bool> visited;

void dfs(int u)
{
    visited[u] = true;

    for (int v : adj_list[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i;
    int a, b, f = 1;

    cin >> n >> m;

    vector <int> degree(n + 1, 0);
    adj_list.resize(n + 1);
    visited.resize(n + 1, false);

    while (m--) {
        cin >> a >> b;

        degree[a]++;
        degree[b]++;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    for (i = 1; i <= n; i++) {
        if (degree[i] != 2) {
            f = 0;

            break;
        }
    }

    dfs(1);

    cout << (f && accumulate(visited.begin(), visited.end(), 0) == n ? "Yes" : "No") << "\n";

    return 0;
}