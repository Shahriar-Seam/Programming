#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int m, n;

    cin >> n >> m;

    if (m < n) {
        swap(m, n);
    }

    if (pair(n, m) >= pair(2, 3)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
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