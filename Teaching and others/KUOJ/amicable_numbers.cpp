#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, m = 1;

    cin >> n;

    for (i = 2; i * i < n; i++) {
        if (n % i == 0) {
            m += i + n / i;
        }
    }

    if (i * i == n) {
        m += i;
    }

    for (i = 2; i * i < m; i++) {
        if (m % i == 0) {
            n -= (i + m / i);
        }
    }

    n--;

    if (i * i == m) {
        n -= i;
    }

    cout << (!n ? m : -1) << "\n";
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