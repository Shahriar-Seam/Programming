#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, l, r;

    cin >> n >> m >> l >> r;

    if (abs(l) > m) {
        cout << -m << " " << 0 << "\n";
    }
    else {
        cout << l << " " << m + l << "\n";
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