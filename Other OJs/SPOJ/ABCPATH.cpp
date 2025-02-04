#include <bits/stdc++.h>

using namespace std;

#define v(i, j) valid(i, j) && !visited[{i, j}]
#define next(i, j, _i, _j) s[i][j] == s[_i][_j] - 1

vector <string> s;
int h, w;
int max_path_len;
map <pair <int, int>, bool> visited;

int valid(int i, int j)
{
    return (i >= 0) && (j >= 0) && (i < h) && (j < w);
}

void dfs(int i, int j)
{
    visited[{i, j}] = true;

    // operation on node
    max_path_len = max(max_path_len, s[i][j] - 'A' + 1);


    if (v(i + 1, j) && next(i, j, i + 1, j)) {
        dfs(i + 1, j);
    }
    if (v(i + 1, j + 1) && next(i, j, i + 1, j + 1)) {
        dfs(i + 1, j + 1);
    }
    if (v(i + 1, j - 1) && next(i, j, i + 1, j - 1)) {
        dfs(i + 1, j - 1);
    }
    if (v(i - 1, j) && next(i, j, i - 1, j)) {
        dfs(i - 1, j);
    }
    if (v(i - 1, j + 1) && next(i, j, i - 1, j + 1)) {
        dfs(i - 1, j + 1);
    }
    if (v(i - 1, j - 1) && next(i, j, i - 1, j - 1)) {
        dfs(i - 1, j - 1);
    }
    if (v(i, j - 1) && next(i, j, i, j - 1)) {
        dfs(i, j - 1);
    }
    if (v(i, j + 1) && next(i, j, i, j + 1)) {
        dfs(i, j + 1);
    }
}

void solve()
{
    int i, j;

    visited.clear();
    s.resize(h);
    max_path_len = 0;

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            visited[{i, j}] = false;
        }
    }

    for (auto &it : s) {
        cin >> it;
    }

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            if (s[i][j] == 'A') {
                dfs(i, j);
            }
        }
    }

    cout << max_path_len << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    // cin >> t;

    for (i = 1; ; i++) {
        cin >> h >> w;

        if (h == 0 && w == 0) {
            break;
        }

        cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}