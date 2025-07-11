#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i, j, ops = 0;

    cin >> n >> k;

    vector <vector <int> > v(n, vector <int> (n));

    for (auto &it : v) {
        for (auto &jt : it) {
            cin >> jt;
        }
    }

    if (n == 1) {
        cout << "YES\n";

        return;
    }

    for (i = 0; i < n / 2; i++) {
        for (j = 0; j < n; j++) {
            if (v[i][j] != v[n - i - 1][n - j - 1]) {
                ops++;
            }
        }
    }

    if (n & 1) {
        for (j = 0, i = n / 2; j < n / 2; j++) {
            if (v[i][j] != v[i][n - j - 1]) {
                ops++;
            }
        }
    }

    if (k < ops) {
        cout << "NO\n";
    }
    else if (n & 1) {
        cout << "YES\n";
    }
    else {
        cout << (((k - ops) % 2 == 0) ? "YES" : "NO") << "\n";
    }
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