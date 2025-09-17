#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, l = -1, r = -1;
    set <int, greater <> > s;

    cin >> n;

    vector <int> v(n);
    
    for (i = 1; i <= n; i++) {
        s.insert(i);
    }

    for (auto &it : v) {
        cin >> it;

        s.erase(it);
    }

    for (i = 0; i < n; i++) {
        if (v[i] == 0) {
            v[i] = *s.begin();

            s.erase(s.begin());
        }
    }

    for (i = 0; i < n; i++) {
        if (v[i] != i + 1) {
            r = i;
        }
    }

    for (i = n - 1; i >= 0; i--) {
        if (v[i] != i + 1) {
            l = i;
        }
    }

    cout << (r == -1 && l == -1 ? 0 : r - l + 1) << "\n";
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