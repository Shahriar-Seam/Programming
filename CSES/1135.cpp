#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
const int LOG = 20;
vector <vector <int> > adj_list, ancestor;
vector <int> parent, depth;
vector <bool> visited;

void init()
{
    adj_list.assign(N, vector <int> ());
    ancestor.assign(N, vector <int> (LOG, 0));
    parent.assign(N + 1, 0);
    depth.assign(N + 1, 0);
    visited.assign(N + 1, false);
}

void dfs(int u)
{
    visited[u] = true;

    if (parent[u] >= 0) {
        depth[u] = depth[parent[u]] + 1;
    }

    ancestor[u][0] = parent[u];

    for (int i = 1; i < LOG; i++) {
        if (ancestor[u][i - 1] >= 0) {
            ancestor[u][i] = ancestor[ancestor[u][i - 1]][i - 1];
        }
        else {
            break;
        }
    }

    for (int v : adj_list[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int lca(int u, int v)
{
    int k, i;

    if (depth[u] < depth[v]) {
        swap(u, v);
    }

    k = depth[u] - depth[v];

    for (i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            u = ancestor[u][i];
        }
    }

    if (u == v) {
        return u;
    }

    for (i = LOG - 1; i >= 0; i--) {
        if (ancestor[u][i] != ancestor[v][i]) {
            u = ancestor[u][i];
            v = ancestor[v][i];
        }
    }

    return ancestor[u][0];
}

void dfs(int u, int p)
{
    parent[u] = p;
    visited[u] = true;

    for (auto &v : adj_list[u]) {
        if (!visited[v]) {
            dfs(v, u);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    int n, q, i, a, b;

    cin >> n >> q;

    for (i = 1; i < n; i++) {
        cin >> a >> b;

        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    dfs(1, 0);

    visited.assign(N + 1, false);

    dfs(1);

    while (q--) {
        cin >> a >> b;

        cout << depth[a] + depth[b] - 2 * depth[lca(a, b)] << "\n";
    }

    return 0;
}