#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, x, y, i, one = 0;
    string s;

    cin >> n >> x >> y >> s;

    vector <int> p(n), a(n), b(n);

    for (auto &it : p) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (s[i] == '1') {
            b[i] = p[i] / 2 + 1;

            y -= b[i];

            one++;
        }
        else {
            a[i] = p[i] / 2 + 1;

            x -= a[i];
        }
    }

    if (x < 0 || y < 0) {
        cout << "NO\n";

        return;
    }

    for (i = 0; i < n; i++) {
        if (s[i] == '1') {
            a[i] = p[i] / 2;

            x -= a[i];
        }
        else {
            b[i] = p[i] / 2;

            y -= b[i];
        }
    }

    if ((x <= 0 && y <= 0) || (x == y) || (one == n && y > x) || (one == 0 && y < x) || (one > 0 && one < n)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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