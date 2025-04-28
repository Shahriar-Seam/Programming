#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b, c;

    cin >> a >> b >> c;

    c -= b - a;

    c -= b;

    if (c >= 0 && (c % 3 == 0)) {
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