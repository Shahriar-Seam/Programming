#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, mask, o, x, min_prod = 1e15;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    if (n > 20) {
        cout << 0 << "\n";

        return;
    }

    for (mask = 1; mask < (1 << n) - 1; mask++) {
        o = x = 0;

        for (i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                o |= v[i];
            }
            else {
                x ^= v[i];
            }
        }

        min_prod = min(min_prod, o * x);
    }

    cout << min_prod << "\n";
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