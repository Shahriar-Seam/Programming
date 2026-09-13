#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x, y, ops = 0, s, i;

    cin >> x >> y;

    s = x + y;

    for (i = 30; i >= 0; i--) {
        if (s & (1 << i)) {
            if ((x & (1 << i)) == (y & (1 << i))) {
                x -= (1 << i);
                
                ops += (1 << i);
            }
        }
        else {
            if ((x & (1 << i)) != (y & (1 << i))) {
                x -= (1 << i);
                y += (1 << i);
                ops += (1 << i);
            }
        }

        y &= ~(1 << i);
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