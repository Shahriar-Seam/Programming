#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, i, t, x, l, r;

    cin >> n >> q;

    vector <int> v(n), pref(n + 1, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + v[i];
    }

    while (q--) {
        cin >> t;

        if (t == 1) {
            cin >> x;

            
        }
        else {
            cin >> l >> r;
        }
    }

    return 0;
}