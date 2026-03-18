#include <bits/stdc++.h>

using namespace std;

vector <int> dx = {1, -1, 0, 0};
vector <int> dy = {0, 0, 1, -1};

int n, m, k, s;
vector <string> v;
vector <vector <bool> > visited;

bool valid(int i, int j)
{
    return min(i, j) >= 0 && i < n && j < m && v[i][j] == '.';
}

void dfs(int i, int j)
{
    if (s == k) {
        return;
    }

    visited[i][j] = true;
    s--;

    for (int d = 0; d < 4; d++) {
        auto x = dx[d];
        auto y = dy[d];

        if (valid(i + x, j + y) && !visited[i + x][j + y] && s > k) {
            dfs(i + x, j + y);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j;

    cin >> n >> m >> k;

    v.assign(n, string (m + 1, 0));
    visited.assign(n, vector <bool> (m, false));
    s = 0;

    for (auto &it : v) {
        cin >> it;

        s += count(it.begin(), it.end(), '.');
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (v[i][j] == '.') {
                dfs(i, j);

                break;
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (v[i][j] == '.' && !visited[i][j] && k) {
                v[i][j] = 'X';
                k--;
            }
        }
    }

    for (auto &it : v) {
        cout << it << "\n";
    }

    return 0;
}