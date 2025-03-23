#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x, y, a;

    cin >> x >> y >> a;

    int k = a / (x + y);

    if (k * (x + y) + x > a) {
        cout << "NO\n";
    }
    else if (k * (x + y) + x + y > a) {
        cout << "YES\n";
    }
    else if (k * (x + y) + x + y + x > a) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
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