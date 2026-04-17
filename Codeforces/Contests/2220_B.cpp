#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, x, i, f;

    cin >> n >> m;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (x = 1; x <= 2; x++) {
        f = 1;

        for (i = 0; i < n; i++) {
            cout << (v[i] + i + x) % m << " ";
            // if ((v[i] + i + x) % m == 0) {
            //     f = 0;

            //     break;
            // }
        }

        if (f == 1) {
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