#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, p;

    cin >> n >> k >> p;

    int moves = (abs(k) + p - 1) / p;

    cout << (moves <= n ? moves : -1) << "\n";
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