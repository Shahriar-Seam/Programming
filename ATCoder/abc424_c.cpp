#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > adj_list;
vector <bool> visited, learned;

void dfs(int u)
{
    visited[u] = true;

    learned[u] = true;

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

    int n, i, u, v;

    cin >> n;
    
    adj_list.assign(n + 1, vector <int> ());
    visited.assign(n + 1, false);
    learned.assign(n + 1, false);

    for (i = 1; i <= n; i++) {
        cin >> u >> v;

        if (u == 0 && v == 0) {
            learned[i] = 1;
        }
        else {
            adj_list[u].push_back(i);
            adj_list[v].push_back(i);
        }
    }

    for (i = 1; i <= n; i++) {
        if (!visited[i] && learned[i]) {
            dfs(i);
        }
    }

    cout << count(learned.begin(), learned.end(), true) << "\n";

    return 0;
}