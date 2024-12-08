#include <bits/stdc++.h>

using namespace std;

#define sz int(1e6)
vector <bool> marked(sz, true);
set <int> available;

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
    set <int> :: iterator it;
    int f = 0;

    it = available.begin();

    while (it != available.end()) {
        if (!marked[abs(*it - p_val)]) {
            f = 1;

            break;
        }

        it++;
    }

    if (f == 0) {
        return -1;
    }
    else {
        int temp = *it;

        available.erase(it);

        return temp;
    }
}

void dfs(vector <vector <int> > &adj_list, vector <int> &values, vector <bool> &visited, vector <int> &parent, int node)
{
    visited[node] = true;

    if (node != 1) {
        values[node] = calculate(values[parent[node]]);
    }

    for (auto it : adj_list[node]) {
        if (!visited[it]) {
            dfs(adj_list, values, visited, parent, it);
        }
    }
}

void solve()
{
    int n, i, u, v, f = 1, root = 1;
    int tu, tv;

    cin >> n;

    vector <pair <int, int> > edges;
    vector <int> parent(n + 1, 0);
    vector <vector <int> > adj_list(n + 1, vector <int> ());
    vector <bool> visited(n + 1, false);
    vector <int> values(n + 1, 0);

    available.clear();

    for (i = 2; i <= 2 * n; i++) {
        available.insert(i);
    }

    for (i = 1; i < n; i++) {
        cin >> u >> v;

        edges.push_back({min(u, v), max(u, v)});

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (i = 1; i <= n; i++) {
        sort(adj_list[i].begin(), adj_list[i].end());
    }

    parent[1] = 0;

    for (i = 2; i <= n; i++) {
        auto nodes = adj_list[i];

        for (auto it : nodes) {
            if (parent[it] != i) {
                parent[i] = it;

                break;
            }
        }
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