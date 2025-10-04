#include <bits/stdc++.h>

using namespace std;

bool possible(vector <int> &v, int n, int m, int ma, int mi)
{
    int high, low, i, f = 0, l, r;
    vector <int> s(n, 0), t(n, 0);
    int s_ma = -1e9, t_mi = 1e9;

    for (i = 0, high = ma + m, low = ma - m; i < n; i++) {
        if (v[i] < low) {
            s[i] = low - v[i];

            s_ma = max(s_ma, s[i]);
        }
    }

    for (i = 0, high = mi + m, low = mi - m; i < n; i++) {
        if (v[i] > high) {
            t[i] = high - v[i];

            t_mi = min(t_mi, t[i]);
        }
    }

    for (i = 0, l = r = -1; i < n; i++) {
        if (s[i] != 0) {
            if (l == -1) {
                l = i;
            }

            r = i;
        }
    }
    
    if (l >= 0) {
        for (i = l, high = ma, low = ma - m; i <= r; i++) {
            if (v[i] + s_ma <= high) {
                // ok
            }
            else {
                f++;

                break;
            }
        }
    }

    for (i = 0, l = r = -1; i < n; i++) {
        if (t[i] != 0) {
            if (l == -1) {
                l = i;
            }

            r = i;
        }
    }

    if (l >= 0) {
        for (i = l, high = mi + m, low = mi; i <= r; i++) {
            if (v[i] + t_mi >= low) {
                // ok
            }
            else {
                f++;

                break;
            }
        }
    }

    return f < 2;
}

void solve()
{
    int n, ma = 0, mi = 1e9;
    int l, r, m, val = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        ma = max(ma, it);
        mi = min(mi, it);
    }

    l = 0, r = val = ma - mi;

    while (l <= r) {
        m = (l + r) / 2;

        if (possible(v, n, m, ma, mi)) {
            val = m;

            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    cout << val << "\n";
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