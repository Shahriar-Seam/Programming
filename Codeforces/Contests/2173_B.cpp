#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    vector <int> a(n), b(n), c, d;

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    a[0] = -a[0];

    c = a;
    d = b;

    for (i = 1; i < n; i++) {
        a[i] = max({a[i - 1] - a[i], b[i - 1] - a[i], c[i - 1] - a[i], d[i - 1] - a[i]});
        b[i] = max({b[i] - a[i - 1], b[i] - b[i - 1], b[i] - c[i - 1], b[i] - d[i - 1]});

        c[i] = min({a[i - 1] - a[i], b[i - 1] - a[i], c[i - 1] - a[i], d[i - 1] - a[i]});
        d[i] = min({b[i] - a[i - 1], b[i] - b[i - 1], b[i] - c[i - 1], b[i] - d[i - 1]});
    }

    for (auto &it : a) {
        cout << it << " ";
    }
    cout << "\n";

    for (auto &it : b) {
        cout << it << " ";
    }
    cout << "\n";

    cout << max(a.back(), b.back()) << "\n";
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