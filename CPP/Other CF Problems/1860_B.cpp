#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int m, k, a1, ak, f = 0;

    cin >> m >> k >> a1 >> ak;

    cout << max(0, (m % k) - a1) + max(0, (m / k) - ak) - min((max(0, a1 - (m % k))) / k, max(0, (m / k) - ak)) << "\n";
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