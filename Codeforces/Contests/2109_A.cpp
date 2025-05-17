#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, f = 1;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    if (n == 2 && v[0] == v[1]) {
        f = 0;
    }

    for (i = 1; i < n; i++) {
        if (v[i] == v[i - 1] && v[i] == 0) {
            f = 0;
        }
    }

    if (count(v.begin(), v.end(), 0) == 0) {
        f = 0;
    }

    cout << (f ? "NO" : "YES") << "\n";
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