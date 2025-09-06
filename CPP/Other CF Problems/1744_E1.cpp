#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int a, b, c, d, ab, x, y, g;

    cin >> a >> b >> c >> d;

    ab = a * b;

    for (x = a + 1; x <= c; x++) {
        g = gcd(ab, x);

        y = ab / g;

        y = (d / y) * y;

        if (y > b) {
            cout << x << " " << y << "\n";

            return;
        }
    }

    cout << "-1 -1\n";
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