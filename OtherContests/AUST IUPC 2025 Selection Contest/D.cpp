#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 1; i < n; i++) {
        if (v[i] > v[0]) {
            cout << i + 1 << "\n";

            return;
        }
    }

    cout << -1 << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    // cin >> t;

    // for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    // }

    return 0;
}