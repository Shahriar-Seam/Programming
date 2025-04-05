#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, x = (1 << 30) - 1;

    cin >> n;

    vector <int> v(n);

    for (i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (i = 0; i < n; i++) {
        if (v[i] != i) {
            x &= v[i];
        }
    }

    cout << x << "\n";
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