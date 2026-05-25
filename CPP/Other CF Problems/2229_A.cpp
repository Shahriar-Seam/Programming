#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, mn = 1e5, mx = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        mn = min(mn, it);
        mx = max(mx, it);
    }

    cout << (mx - mn + 1) / 2 << "\n";
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