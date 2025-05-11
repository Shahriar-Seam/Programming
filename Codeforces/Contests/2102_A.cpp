#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, p, q, i, j;
    int temp;

    cin >> n >> m >> p >> q;

    vector <int> v(n, 0), vv;

    for (i = 0; i < n; i += p) {
        v[i] = q;
    }

    int total = accumulate(v.begin(), v.end(), 0);
    temp = total - m;
    vv = v;

    if (p == 1 && temp != 0) {
        cout << "NO\n";

        return;
    }

    for (i = 0; i < n; i += p) {
        v[i] -= temp;

        if (i + 1 < n) {
            v[i + 1] += temp;
        }
    }

    for (i = 0; i < n; i += p) {
        vv[i] += temp;

        if (i + 1 < n) {
            vv[i + 1] -= temp;
        }
    }

    if ((accumulate(v.begin(), v.end(), 0) != m) && (accumulate(vv.begin(), vv.end(), 0) != m)) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
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