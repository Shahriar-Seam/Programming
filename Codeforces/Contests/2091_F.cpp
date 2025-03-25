#include <bits/stdc++.h>

using namespace std;

int square(int n)
{
    return n * n;
}

int dist(pair <int, int> p1, pair <int, int> p2, int d)
{
    return square(p1.first - p2.first) + square(p1.second - p2.second) <= d;
}

int recurse(vector <string> &v, int i, int j, vector <vector <int> > &memo, int d, vector <vector <int> > &coordinates, vector <vector <bool> > &visited)
{
    if (j < 0 || j >= v[0].size()) {
        return 0;
    }

    visited[i][j] = true;

    if (memo[i][j] == -1) {
        memo[i][j] = 0;

        for (int k = i; k >= 0; k--) {
            for (auto l : coordinates[k]) {
                if (i == 0 && dist({k, l}, {i, j}, d)) {
                    memo[i][j]++;

                    continue;
                }

                if (dist({k, l}, {i, j}, d) && !visited[k][l]) {
                    cout << i << " " << j << " " << k << " " << l << "\n";
                    memo[i][j] += recurse(v, k, l, memo, d, coordinates, visited);
                }
            }
        }
    }

    visited[i][j] = false;

    return memo[i][j];
}

void solve()
{
    int n, m, d, i, j;

    cin >> n >> m >> d;

    d *= d;

    vector <string> v(n);
    vector <vector <int> > coordinates(n);
    vector <vector <int> > memo(n, vector <int> (m, -1));
    vector <vector <bool> > visited(n, vector <bool> (m, false));

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (v[i][j] == 'X') {
                coordinates[i].push_back(j);
            }
        }
    }

    // for (i = 0; i < n; i++) {
    //     cout << i << ": ";

    //     for (auto it : coordinates[i]) {
    //         cout << it << " ";
    //     }

    //     cout << "\n";
    // }
    // cout << "\n";

    int sum = 0;

    for (i = 0; i < m; i++) {
        if (v[n - 1][i] == 'X') {
            visited.resize(n, vector <bool> (m, false));

            sum += recurse(v, n - 1, i, memo, d, coordinates, visited);
        }
    }
    
    cout << sum << "\n";
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