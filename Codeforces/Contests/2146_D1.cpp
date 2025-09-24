#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int l, r, p, n, i, x;
    set <int> s;

    cin >> l >> r;

    for (i = l; i <= r; i++) {
        s.insert(i);
    }

    n = r - l + 1;

    vector <int> v(n, -1);

    p = (1 << (32 - __builtin_clz((int32_t) r)));

    for (p = p; p > 0; p /= 2) {
        for (i = l; i <= r; i++) {
            if (v[i] == -1) {
                if (s.find(i ^ (p - 1)) != s.end()) {
                    v[i] = i ^ (p - 1);

                    s.erase(v[i]);
                }
            }
        }
    }

    for (i = l; i <= r; i++) {
        x += (i | v[i]);
    }

    cout << x << "\n";

    for (i = 0; i < n; i++) {
        cout << v[i] << " ";
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