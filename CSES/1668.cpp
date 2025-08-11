#include <bits/stdc++.h>

using namespace std;

vector <int> color;
vector <bool> visited;
int bipartite = 1;

void bfs(vector <vector <int> > &adj_list, int root)
{
    int u;
    queue <int> q;

    q.push(root);

    while (!q.empty()) {
        u = q.front();
        q.pop();

        visited[u] = true;

        if (color[u] == -1) {
            color[u] = 1;
        }

        for (auto v : adj_list[u]) {
            if (!visited[v]) {
                if (color[v] == color[u]) {
                    bipartite = 0;
                }
                else {
                    if (color[u] == 1) {
                        color[v] = 2;
                    }
                    else {
                        color[v] = 1;
                    }
                }

                q.push(v);
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, u, v;

    cin >> n >> m;

    vector <vector <int> > adj_list(n + 1);
    visited.assign(n + 1, false);
    color.assign(n + 1, -1);

    for (i = 0; i < m; i++) {
        cin >> u >> v;

        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }

    for (i = 1; i <= n; i++) {
        if (!visited[i]) {
            bfs(adj_list, i);
        }
    }

    if (bipartite) {
        for (i = 1; i <= n; i++) {
            cout << color[i] << " ";
        }

        cout << "\n";
    }
    else {
        cout << "IMPOSSIBLE\n";
    }

    return 0;
}