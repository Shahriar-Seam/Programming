#include <bits/stdc++.h>

using namespace std;

int lg2(int n)
{
    int l = 0;

    while (n > 0) {
        n >>= 1;

        l++;
    }

    return l - 1;
}

void solve()
{
    int x, y = 0, z;

    cin >> x;

    y = (1 << (lg2(x) - 1)) - 1;

    z = x ^ y;

    if (x + y > z && y + z > x && z + x > y) {
        cout << y << "\n";
    }
    else {
        y = (1 << (lg2(x) - 1)) + 1;
        
        z = x ^ y;

        if (x + y > z && y + z > x && z + x > y) {
            cout << y << "\n";
        }
        else {
            cout << -1 << "\n";
        }
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