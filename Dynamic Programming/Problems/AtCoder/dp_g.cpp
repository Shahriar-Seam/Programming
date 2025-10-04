#include <bits/stdc++.h>

using namespace std;

int dfs(vector <vector <int> > &adj_list, int u, vector <int> &dp, vector <bool> &visited)
{
    visited[u] = true;
    int max_len = 0;

    for (auto &v : adj_list[u]) {
        if (!visited[v]) {
            max_len = max(max_len, 1 + dfs(adj_list, v, dp, visited));
        }
        else {
            max_len = max(max_len, 1 + dp[v]);
        }
    }

    return dp[u] = max_len;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x, y, i;

    cin >> n >> m;

    vector <vector <int> > adj_list(n + 1);
    vector <int> dp(n + 1, -1);
    vector <bool> visited(n + 1, false);

    for (i = 0; i < m; i++) {
        cin >> x >> y;

        adj_list[x].push_back(y);
    }

    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(adj_list, i, dp, visited);
        }
    }

    cout << *max_element(dp.begin(), dp.end()) << "\n";

    return 0;
}