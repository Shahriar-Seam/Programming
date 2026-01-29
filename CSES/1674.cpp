#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > adj_list;
vector <int> subordinates;
vector <bool> visited;

int dfs(int u)
{
    visited[u] = true;

    int count = 1;

    for (int v : adj_list[u]) {
        if (!visited[v]) {
            count += dfs(v);
        }
    }

    return subordinates[u] = count;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, u;

    cin >> n;

    adj_list.assign(n + 1, vector <int> ());
    subordinates.assign(n + 1, 0);
    visited.assign(n + 1, false);

    for (i = 2; i <= n; i++) {
        cin >> u;

        adj_list[u].push_back(i);
    }

    dfs(1);

    for (i = 1; i <= n; i++) {
        cout << subordinates[i] - 1 << " ";
    }

    return 0;
}