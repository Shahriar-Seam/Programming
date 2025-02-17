#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int l, r, g, x, min_lcm = 1e18;

    cin >> l >> r;

    for (g = 1; g * g <= r; g++) {
        x = ((l - 1) / g) + 1;

        if (g * (x + 1) <= r) {
            min_lcm = min(min_lcm, g * x * (x + 1));
        }
    }

    for (x = 1; x * x <= r; x++) {
        g = ((l - 1) / x) + 1;

        if (g * (x + 1) <= r) {
            min_lcm = min(min_lcm, g * x * (x + 1));
        }
    }

    cout << min_lcm << "\n";
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