#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, q, l, r;

    cin >> n;

    vector <int> v(n), diff(n + 1, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 1, diff[1] = 1; i < n; i++) {
        diff[i + 1] = diff[i] + (v[i] != v[i - 1]);
    }

    cin >> q;

    while (q--) {
        cin >> l >> r;

        if (diff[l] == diff[r]) {
            cout << "-1 -1\n";
        }
        else {
            cout << max(l, int(lower_bound(diff.begin(), diff.end(), diff[r] - 1) - diff.begin())) << " " << r << "\n";
        }
    }

    cout << "\n";
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