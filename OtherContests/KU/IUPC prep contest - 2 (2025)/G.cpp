#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int l, w, x, a, b, c, d, crash = 0;

    cin >> l >> w >> x >> a >> b >> c >> d;

    if ((abs(c - a) % x) != 0) {
        if (((c % x) == 0) || (((l - c) % x) == 0)) {
            crash++;
        }
        else {
            cout << "-1\n";

            return;
        }
    }

    if ((abs(d - b) % x) != 0) {
        if (((d % x) == 0) || (((w - d) % x) == 0)) {
            crash++;
        }
        else {
            cout << "-1\n";

            return;
        }
    }

    cout << crash << "\n";
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