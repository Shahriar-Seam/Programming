#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, j;

    cin >> n >> k;

    cout << k << " ";

    for (j = 1; j < n - 1; j++) {
        cout << "0 ";
    }

    if (n > 1) {
        cout << k;
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