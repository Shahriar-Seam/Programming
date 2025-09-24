#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, x0 = 0, x1 = 0, q, tp, l, r, g;
    string s;

    cin >> n;

    vector <int> v(n), pref(n + 1, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        pref[i + 1] = pref[i] ^ v[i];
    }

    cin >> s;

    for (i = 0; i < n; i++) {
        if (s[i] == '0') {
            x0 ^= v[i];
        }
        else {
            x1 ^= v[i];
        }
    }

    cin >> q;

    while (q--) {
        cin >> tp;

        if (tp == 1) {
            cin >> l >> r;

            x0 ^= pref[l - 1];
            x0 ^= pref[r];

            x1 ^= pref[l - 1];
            x1 ^= pref[r];
        }
        else {
            cin >> g;

            if (g == 0) {
                cout << x0 << " ";
            }
            else {
                cout << x1 << " ";
            }
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