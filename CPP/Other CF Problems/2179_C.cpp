#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, mn = 1e9 + 5, k = 1;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        mn = min(mn, it);
    }

    k = mn;
    mn = 1e9 + 5;

    for (auto &it : v) {
        if (it != k) {
            mn = min(mn, it - k);
        }
    }

    k = max(k, mn);

    cout << k << "\n";
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