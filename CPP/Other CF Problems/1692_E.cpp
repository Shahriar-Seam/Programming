#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, s, i, min_ops = 1e9;

    cin >> n >> s;

    vector <int> v(n), pref(n + 1, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + v[i];
    }

    if (pref[n] < s) {
        cout << -1 << "\n";

        return;
    }

    for (i = n; pref[i] >= s; i--) {
        auto it = lower_bound(pref.begin(), pref.end(), pref[i] - s);

        min_ops = min(min_ops, int((it - pref.begin()) + (n - i)));
    }

    cout << min_ops << "\n";
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