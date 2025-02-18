#include <bits/stdc++.h>

using namespace std;

int n, m;
vector <vector <bool> > visited(705, vector <bool> (705, false));
vector <vector <int> > v;
map <int, int> counter;

bool valid(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int i, int j, int p, int d)
{
    if (v[i][j] != p) {
        return;
    }
    
    counter[v[i][j]] = max(counter[v[i][j]], d);

    visited[i][j] = true;

    if (valid(i + 1, j) && !visited[i + 1][j]) {
        dfs(i + 1, j, v[i][j], d + 1);
    }
    if (valid(i, j + 1) && !visited[i][j + 1]) {
        dfs(i, j + 1, v[i][j], d + 1);
    }
    if (valid(i - 1, j) && !visited[i - 1][j]) {
        dfs(i - 1, j, v[i][j], d + 1);
    }
    if (valid(i, j - 1) && !visited[i][j - 1]) {
        dfs(i, j - 1, v[i][j], d + 1);
    }
}

void solve()
{
    int i, j, jhamela = 0;
    long long total = 0;

    cin >> n >> m;

    v.resize(n, vector <int> (m));
    visited.assign(705, vector <bool> (705, false));
    counter.clear();
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (!visited[i][j]) {
                counter[v[i][j]] = 1;
                dfs(i, j, v[i][j], 1);
            }
        }
    }
    
    for (auto it : counter) {
        total += it.second;

        jhamela = max(jhamela, it.second);
    }

    cout << total - jhamela << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}