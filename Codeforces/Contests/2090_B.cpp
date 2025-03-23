#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i, j, k, f;

    cin >> n >> m;

    vector <string> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = n - 1; i >= 0; i--) {
        for (j = m - 1; j >= 0; j--) {
            if (v[i][j] == '1') {
                f = 0;

                for (k = i; k >= 0; k--) {
                    if (v[k][j] != '1') {
                        f++;

                        break;
                    }
                }
                for (k = j; k >= 0; k--) {
                    if (v[i][k] != '1') {
                        f++;

                        break;
                    }
                }

                if (f > 1) {
                    cout << "NO\n";

                    return;
                }
            }
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