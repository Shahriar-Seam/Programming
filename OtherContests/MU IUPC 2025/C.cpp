#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, m, k, p = 0;

    cin >> n >> m;

    if (m & 1) {
        cout << -1 << "\n";

        return;
    }

    m /= 2;

    while (m > 0) {
        k = min(n, m);

        if ((m % 2) != (k % 2)) {
            k--;
        }

        p += k;

        m = (m - k) / 2;
    }

    cout << p << "\n";
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