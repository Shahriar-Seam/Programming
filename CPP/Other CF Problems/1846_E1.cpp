#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;

    cin >> n;

    for (k = 2; k < 1000; k++) {
        if (n - (k * (k + 1) - 1) >= 0 && (n - (k * (k + 1)) - 1) % k == 0) {
            cout << k << " " << "YES\n";

            return;
        }
    }

    cout << "NO\n";
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