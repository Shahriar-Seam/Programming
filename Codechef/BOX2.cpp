#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x, y, k, min_time = 1e9, i;

    cin >> x >> y >> k;

    for (i = 0; i <= 10; i++) {
        if (abs(x + i - y + i) == k || abs(y + i - x + i) == k) {
            min_time = min(min_time, i);
        }
    }

    cout << (min_time == 1e9 ? -1 : min_time) << '\n';
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