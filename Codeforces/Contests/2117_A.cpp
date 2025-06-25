#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, x, i, f = -1, l = -1, temp;

    cin >> n >> x;

    for (i = 0; i < n; i++) {
        cin >> temp;

        if (temp == 1 && f == -1) {
            f = i;
        }

        if (temp == 1) {
            l = i;
        }
    }

    if (f < 0) {
        cout << "YES\n";
    }
    else if (l - f + 1 <= x) {
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