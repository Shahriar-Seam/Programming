#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x, y;

    cin >> x >> y;

    if (y == 0) {
        cout << 1 << "\n";
    }
    else if (x < y) {
        cout << 2 << "\n";
    }
    else if (y > 1 && y < x - 1) {
        cout << 3 << "\n";
    }
    else {
        cout << -1 << "\n";
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