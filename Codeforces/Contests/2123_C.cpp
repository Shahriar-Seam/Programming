#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    vector <int> v(n), p(n), s(n);

    for (auto &it : v) {
        cin >> it;
    }

    p[0] = v[0];
    s[n - 1] = v[n - 1];

    for (i = 1; i < n; i++) {
        p[i] = min(p[i - 1], v[i]);
    }

    for (i = n - 2; i >= 0; i--) {
        s[i] = max(s[i + 1], v[i]);
    }

    for (i = 0; i < n; i++) {
        if (v[i] == p[i] || v[i] == s[i]) {
            cout << 1;
        }
        else {
            cout << 0;
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