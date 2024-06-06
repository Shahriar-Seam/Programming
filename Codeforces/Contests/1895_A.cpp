#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, x, y, k, ans, m;

    cin >> t;

    while (t--) {
        cin >> x >> y >> k;

        if (x >= y) {
            cout << x << "\n";
        }
        else {
            m = y - (x + k);

            m = m > 0 ? m : 0;

            ans = min({y + m, y + (y - x)});

            cout << ans << "\n";
        }
    }

    return 0;
}