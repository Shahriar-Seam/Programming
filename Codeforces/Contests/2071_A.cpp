#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int k;

    cin >> k;

    cout << ((k % 3 == 1) ? "YES" : "NO") << "\n";
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