#include <bits/stdc++.h>

using namespace std;

int f(vector <vector <int> > &pref, int l, int r)
{
    if (l > r) {
        return -1;
    }

    int i, n = (1 << 30) - 1;

    for (i = 0; i < 31; i++) {
        if ((pref[r][i] > pref[l - 1][i])) {
            n &= ~(1 << i);
        }
    }

    return n;
}

void solve()
{
    int n, i, j, k, q;
    int l, r, L, R, m;

    cin >> n;

    vector <int> v(n);
    vector <vector <int> > pref(n + 5, vector <int> (32, 0));

    for (i = 0; i < n; i++) {
        cin >> v[i];

        for (j = 0; j < 31; j++) {
            pref[i + 1][j] = pref[i][j];

            if (!(v[i] & (1 << j))) {
                pref[i + 1][j]++;
            }
        }
    }

    cin >> q;

    while (q--) {
        cin >> l >> k;

        L = l, R = n;

        while (L <= R) {
            m = (L + R) / 2;

            if (f(pref, l, m) >= k) {
                L = m + 1;
                r = m;
            }
            else {
                R = m - 1;
            }
        }

        if (f(pref, l, r) >= k) {
            cout << r << " ";
        }
        else {
            cout << "-1 ";
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