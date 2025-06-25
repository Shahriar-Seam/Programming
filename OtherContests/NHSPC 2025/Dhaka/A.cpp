#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > adj_list;
vector <bool> visited;
int max_depth = 0;

void dfs(int u, int &depth)
{
    visited[u] = true;

    max_depth = max(max_depth, depth);

    for (int v : adj_list[u]) {
        if (!visited[v]) {
            depth++;
            
            dfs(v, depth);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, u, v;
    int depth;

    cin >> n >> m;

    adj_list.resize(n + 1);
    visited.resize(n + 1, false);

    for (i = 0; i < m; i++) {
        cin >> u >> v;;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            depth = 1;

            dfs(i, depth);
        }
    }

    cout << max_depth << "\n";

    return 0;
}