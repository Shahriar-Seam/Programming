#include <bits/stdc++.h>

using namespace std;

bool dfs(vector <vector <int> > &adj_list, vector <bool> &visited, int u, int t) {
    if (u == t) {
        return true;
    }

    bool f = false;

    visited[u] = true;

    for (auto &v : adj_list[u]) {
        if (!visited[v]) {
            f |= dfs(adj_list, visited, v, t);
        }
    }

    return f;
}

bool check(vector <vector <int> > &adj_list, string &s, string &t)
{
    int i;

    if (s.size() != t.size()) {
        return false;
    }

    for (i = 0; i < s.size(); i++) {
        vector <bool> visited(128, false);

        if (!dfs(adj_list, visited, s[i], t[i])) {
            return false;
        }
    }

    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, i, j;
    char a, b, c;
    string s, t;
    vector <vector <int> > adj_list(128);

    cin >> m >> n;

    for (i = 0; i < m; i++) {
        cin >> a >> b;

        adj_list[a].push_back(b);
    }

    for (i = 0; i < n; i++) {
        cin >> s >> t;

        cout << (check(adj_list, s, t) ? "yes" : "no") << "\n";
    }

    return 0;
}