#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x, y, z, c, g, r, coins, cnt;

    cin >> x >> y >> z >> c;

    if (x == y) {
        cout << 0 << "\n";

        return;
    }

    if (x < y) {
        swap(x, y);
    }

    coins = 2 * c;

    g = gcd(x, y);

    r = (z / g) * g;

    for (r = r, cnt = 0; r > 0 && cnt < 5000; r -= g, cnt++) {
        if (z - r > 2 * c) {
            break;
        }

        if (gcd(x, r) == lcm(y, r)) {
            coins = min(coins, z - r + c);

            break;
        }
    }

    for (r = ((z / g) * g) + g, cnt = 0; cnt < 5000; r += g, cnt++) {
        if (r - z > 2 * c) {
            break;
        }

        if (gcd(x, r) == lcm(y, r)) {
            coins = min(coins, r - z + c);

            break;
        }
    }

    cout << coins << "\n";
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