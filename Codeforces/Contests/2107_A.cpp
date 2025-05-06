#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, g;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        g = 0;

        for (j = 0; j < n; j++) {
            if (i != j) {
                g = gcd(g, v[j]);
            }
        }

        if (g != v[i]) {
            cout << "YES\n";

            for (j = 0; j < n; j++) {
                if (j != i) {
                    cout << 1 << " ";
                }
                else {
                    cout << 2 << " ";
                }
            }

            cout << "\n";

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