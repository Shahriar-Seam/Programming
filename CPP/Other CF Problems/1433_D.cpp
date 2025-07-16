#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, val = 0, change = 0, i, index;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        if (it != val) {
            val = it;
            change++;
        }
    }

    if (change == 1) {
        cout << "NO\n";

        return;
    }

    cout << "YES\n";

    for (i = 1; i < n; i++) {
        if (v[i] != v[0]) {
            index = i + 1;

            cout << 1 << " " << i + 1 << "\n";
        }
    }

    for (i = 1; i < n; i++) {
        if (v[i] == v[0]) {
            cout << index << " " << i + 1 << "\n";
        }
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