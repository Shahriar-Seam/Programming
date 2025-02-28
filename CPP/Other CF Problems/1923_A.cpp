#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, f = -1, l = -1, i, count = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (f < 0 && v[i] == 1) {
            f = i;
        }

        if (v[i] == 1) {
            l = i;
        }
    }

    for (i = f; i <= l; i++) {
        count += (v[i] == 0);
    }

    cout << count << "\n";
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