#include <bits/stdc++.h>

using namespace std;

#define sz int(1e6)
vector <bool> marked(sz, true);
int x;

void sieve()
{
    int i, j;

    marked[0] = marked[1] = false;

    for (i = 4; i < sz; i += 2) {
        marked[i] = false;
    }

    for (i = 3; i * i < sz; i += 2) {
        if (marked[i]) {
            for (j = i * i; j < sz; j += i + i) {
                marked[j] = false;
            }
        }
    }
}

int calculate(int p_val)
{
    int f = 0;

    for (x; ; x++) {
        if ((abs(x - p_val) > 0) && !marked[abs(x - p_val)]) {
            f = 1;

            break;
        }
    }

    if (f == 0) {
        return -1;
    }
    else {
        int temp = x;
        
        x++;
        
        return temp;
    }
}

void dfs(vector <vector <int> > &adj_list, vector <int> &values, vector <bool> &visited, int parent, int node)
{
    visited[node] = true;

    if (node != 1) {
        values[node] = calculate(values[parent]);
    }

    for (auto it : adj_list[node]) {
        if (!visited[it]) {
            dfs(adj_list, values, visited, node, it);
        }
    }
}

void solve()
{
    int n, i, u, v, f = 1, root = 1, parent = 0;
    int tu, tv;

    cin >> n;

    vector <pair <int, int> > edges;
    vector <vector <int> > adj_list(n + 1, vector <int> ());
    vector <bool> visited(n + 1, false);
    vector <int> values(n + 1, 0);

    x = 1;

    for (i = 1; i < n; i++) {
        cin >> u >> v;

        edges.push_back({min(u, v), max(u, v)});

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (i = 1; i <= n; i++) {
        sort(adj_list[i].begin(), adj_list[i].end());
    }

    values[root] = 1;

    dfs(adj_list, values, visited, parent, root);

    for (i = 1; i <= n; i++) {
        if (values[i] == -1) {
            f = 0;

            break;
        }
    }

    if (f == 0) {
        cout << -1;
    }
    else {
        for (i = 1; i <= n; i++) {
            cout << values[i] << " ";
        }
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}