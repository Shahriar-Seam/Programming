#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    c -= a;
    d -= b;

    if (max(a, b) - (min(a, b) + 1) * 2
     > 0 || max(c, d) - (min(c, d) + 1) * 2 > 0) {
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