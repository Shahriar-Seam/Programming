#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, m, i, j, sum = 0, temp;
    int x = 0, y = 0;
    string s;

    cin >> n >> m >> s;

    vector <vector <int> > v(n, vector <int> (m));
    vector <int> row_sum, col_sum;

    for (auto &it : v) {
        for (auto &itt : it) {
            cin >> itt;
        }
    }
    
    for (i = 0; i < n; i++) {
        row_sum.push_back(accumulate(v[i].begin(), v[i].end(), 0LL));
    }

    for (j = 0; j < m; j++) {
        temp = 0LL;

        for (i = 0; i < n; i++) {
            temp += v[i][j];
        }

        col_sum.push_back(temp);
    }

    for (i = 0; i < n + m - 2; i++) {
        // fix row
        // x row
        // y col
        if (s[i] == 'D') {
            v[x][y] = sum - row_sum[x];
            col_sum[y] += sum - row_sum[x];
            row_sum[x] = sum;
            x++;
        }
        else {
            v[x][y] = sum - col_sum[y];
            row_sum[x] += sum - col_sum[y];
            col_sum[y] = sum;
            y++;
        }
    }

    v[n - 1][m - 1] = -row_sum[n - 1];

    for (auto it : v) {
        for (auto itt : it) {
            cout << itt << " ";
        }

        cout << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}