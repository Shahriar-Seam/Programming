#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int x, y, k;

    cin >> x >> y >> k;

    cout << k + (k + (k * y) - 1 + x - 2) / (x - 1) << "\n";
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