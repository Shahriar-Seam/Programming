#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int l, r, i, j, min_lcm = 2e9;

    cin >> l >> r;

    for (i = l; i < r; i++) {
        for (j = i + 1; j <= r; j++) {
            min_lcm = min(min_lcm, lcm(i, j));
        }
    }

    cout << min_lcm << "\n";

    for (i = l; i < r; i++) {
        for (j = i + 1; j <= r; j++) {
            if (lcm(i, j) == min_lcm) {
                cout << i << " " << j << "\n";
            }
        }
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
        cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}