#include <bits/stdc++.h>

using namespace std;

#define int long long

int mod_dec(int n, int m)
{
    return ((n - 1) + m) % m;
}

int mod_inc(int n, int m)
{
    return (n + 1) % m;
}

void solve()
{
    int n, i, l, r, w, mxl, mxr;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        l = mod_dec(i, n);
        r = i;
        w = 0;
        mxl = mxr = 0;

        while (l != r) {
            if (v[l] < v[r]) {
                mxl = max(mxl, v[l]);

                w += mxl;

                l = mod_dec(l, n);
            }
            else {
                mxr = max(mxr, v[r]);

                w += mxr;

                r = mod_inc(r, n);
            }
        }

        cout << w << " ";
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