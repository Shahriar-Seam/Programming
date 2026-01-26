#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, q, i, l, r;

    cin >> n >> q;

    vector <int> a(n), b(n), v(n + 1, 0), pref(n + 1, 0);

    for (i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (i = 0; i < n; i++) {
        cin  >> b[i];
    }

    for (i = n - 1; i >= 0; i--) {
        v[i] = max({a[i], b[i], v[i + 1]});
    }

    for (i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + v[i];
    }

    while (q--) {
        cin >> l >> r;

        cout << pref[r] - pref[l - 1] << " ";
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