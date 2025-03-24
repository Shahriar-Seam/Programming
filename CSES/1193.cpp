#include <bits/stdc++.h>

using namespace std;

#define valid(i, j, n, m) (i >= 0 && i < n && j >= 0 && j < m)

// * todo: use bfs

void dfs(vector <string> &v, vector <vector <bool> > &visited, int i, int j, int n, int m, string &s, string &path)
{
    if (!valid(i, j, n, m) || v[i][j] == '#') {
        return;
    }

    visited[i][j] = true;

    if (v[i][j] == 'B') {
        if (path.size() > s.size()) {
            path = s;
        }

        return;
    }

    s += 'D';
    dfs(v, visited, i + 1, j, n, m, s, path);
    s.pop_back();

    s += 'U';
    dfs(v, visited, i - 1, j, n, m, s, path);
    s.pop_back();

    s += 'R';
    dfs(v, visited, i, j + 1, n, m, s, path);
    s.pop_back();

    s += 'L';
    dfs(v, visited, i, j - 1, n, m, s, path);
    s.pop_back();
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j;

    cin >> n >> m;

    vector <string> v(n);
    vector <vector <bool> > visited(n, vector <bool > (m, false));
    string s = "", path(1000009, 'S');

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (v[i][j] == 'A') {
                dfs(v, visited, i, j, n, m, s, path);
            }
        }
    }

    if (path.size() != 1000009) {
        cout << "YES" << "\n";
        cout << path.size() << "\n";
        cout << path << "\n";
    }
    else {
        cout << "NO" << "\n";
    }

    return 0;
}