#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, l, r, m, max_len;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 1; i <= n; i++) {
        l = 1, r = i;

        while (l <= r) {
            m = (l + r) / 2;

            if (v.begin() + i - lower_bound(v.begin(), v.end(), m) >= m) {
                max_len = m;

                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }

        cout << max_len << " ";
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