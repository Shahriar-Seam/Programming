#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i, j;

    cin >> n >> m;

    vector <vector <int> > a(n, vector <int> (m)), b(n, vector <int> (m));
    vector <set <int> > row_a(n, set <int> ()), row_b(n, set <int> ());
    vector <set <int> > col_a(m, set <int> ()), col_b(m, set <int> ());

    for (auto &it : a) {
        for (auto &jt : it) {
            cin >> jt;
        }
    }

    for (auto &it : b) {
        for (auto &jt : it) {
            cin >> jt;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            row_a[i].insert(a[i][j]);
            col_a[j].insert(a[i][j]);

            row_b[i].insert(b[i][j]);
            col_b[j].insert(b[i][j]);
        }
    }

    sort(row_a.begin(), row_a.end());
    sort(row_b.begin(), row_b.end());
    sort(col_a.begin(), col_a.end());
    sort(col_b.begin(), col_b.end());

    for (i = 0; i < n; i++) {
        if (row_a[i] != row_b[i]) {
            cout << "NO\n";

            return;
        }
    }

    for (j = 0; j < m; j++) {
        if (col_a[j] != col_b[j]) {
            cout << "NO\n";

            return;
        }
    }

    cout << "YES\n";
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