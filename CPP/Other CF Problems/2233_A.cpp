#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, x, y, z, h1 = 0, h2 = 0, temp;

    cin >> n >> x >> y >> z;

    temp = n;

    while (temp > 0) {
        temp -= x;

        if (z) {
            z--;
        }
        else {
            temp -= 10 * y;
        }

        h1++;
    }

    temp = n;

    while (temp > 0) {
        temp -= x + y;

        h2++;
    }

    cout << min(h1, h2) << "\n";
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