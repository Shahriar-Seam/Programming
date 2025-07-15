#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, l, r;
    set <int> s;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        s.insert(it);
    }

    if (n <= 3) {
        cout << -1 << "\n";

        return;
    }

    l = 0;
    r = n - 1;

    while (r > l) {
        if (r - l < 3) {
            cout << -1 << "\n";

            return;
        }

        auto mn = *s.begin();
        auto mx = *s.rbegin();

        if (v[l] == mn || v[l] == mx) {
            s.erase(v[l]);

            l++;
        }
        else if (v[r] == mn || v[r] == mx) {
            s.erase(v[r]);
            
            r--;
        }
        else {
            cout << l + 1 << " " << r + 1 << "\n";

            return;
        }
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