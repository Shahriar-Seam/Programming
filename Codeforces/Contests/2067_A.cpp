#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x, y, n;

    cin >> x >> y;

    if (x > y) {
        if ((x - y) % 9 == 8) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    else if (x + 1 == y) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
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