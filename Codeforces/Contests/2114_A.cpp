#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;

    cin >> n;

    int r = sqrt(n);

    if (n == 0) {
        cout << "0 0\n";
    }
    else if (r * r == n) {
        cout << r - 1 << " " << 1 << "\n";
    }
    else if ((r + 1) * (r + 1) == n) {
        cout << r << " " << 1 << "\n";
    }
    else {
        cout << -1 << "\n";
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