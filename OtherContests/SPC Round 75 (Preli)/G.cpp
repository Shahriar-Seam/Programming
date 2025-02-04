#include <bits/stdc++.h>

using namespace std;

#define int long long

vector <vector <int> > adj_list;
vector <bool> visited;

int dfs1(int u, vector <int> &temp)
{
    visited[u] = true;
    temp[u] = 1;

    for (int v : adj_list[u]) {
        if (!visited[v]) {
            temp[u] += dfs1(v, temp);
        }
    }

    return temp[u];
}

void dfs2(int u, vector <int> &temp, int &sum, int n)
{
    visited[u] = true;

    for (int v : adj_list[u]) {
        if (!visited[v]) {
            sum += temp[v] * (n - temp[v]);

            dfs2(v, temp, sum, n);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, u, v, sum = 0;

    cin >> n;

    adj_list.resize(n + 1, vector <int> ());
    visited.assign(n + 1, false);
    vector <int> temp(n + 1);

    for (i = 1; i < n; i++) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    dfs1(1, temp);

    visited.assign(n + 1, false);
    
    dfs2(1, temp, sum, n);

    cout << sum * 4 << "\n";

    return 0;
}