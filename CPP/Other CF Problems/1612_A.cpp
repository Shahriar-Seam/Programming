#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x, y;

    cin >> x >> y;

    if ((x + y) & 1) {
        cout << "-1 -1\n";
    }
    else {
        cout << x / 2 << " " << ((x + y) / 2) - (x / 2) << "\n";
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