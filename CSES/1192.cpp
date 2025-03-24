#include <bits/stdc++.h>

using namespace std;

#define valid(i, j, n, m) (i >= 0 && i < n && j >= 0 && j < m)

void dfs(vector <string> &v, vector <vector <bool> > &visited, int i, int j, int n, int m)
{
    if (!valid(i, j, n, m) || visited[i][j] || v[i][j] == '#') {
        return;
    }

    visited[i][j] = true;

    dfs(v, visited, i + 1, j, n, m);
    dfs(v, visited, i - 1, j, n, m);
    dfs(v, visited, i, j + 1, n, m);
    dfs(v, visited, i, j - 1, n, m);
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j, rooms = 0;

    cin >> n >> m;

    vector <string> v(n);
    vector <vector <bool> > visited(n, vector <bool > (m, false));

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (!visited[i][j] && v[i][j] == '.') {
                dfs(v, visited, i, j, n, m);

                rooms++;
            }
        }
    }

    cout << rooms << "\n";

    return 0;
}