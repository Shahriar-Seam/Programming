#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, m, i, j, k, f;

    cin >> n >> m;

    vector <vector <int> > v(n, vector <int> (m));

    for (auto &it : v) {
        for (auto &jt : it) {
            cin >> jt;
        }
    }

    for (k = 0; k < 50; k++) {
        f = 0;

        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                if (v[i][j] & (1LL << k)) {
                    f++;

                    break;
                }
            }
        }

        if (f == n) {
            cout << "YES\n";

            return;
        }
    }

    cout << "NO\n";
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