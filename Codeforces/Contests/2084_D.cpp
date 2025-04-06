#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, k, i;

    cin >> n >> m >> k;

    if (m == 1) {
        for (i = 0; i < n; i++) {
            cout << i % (n - k) << " ";
        }
    }
    else {
        for (i = 0; i < n; i++) {
            cout << i % m << " ";
        }
    }

    cout << "\n";
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