#include <bits/stdc++.h>

using namespace std;

#define int long long

bool valid(int a, int b, int c, int d, int m)
{
    return ceil((c * 1.0 / d) * m) - ceil((a * 1.0 / b) * m) >= 1;
}

void solve()
{
    int a, b, c, d;
    int l = 1, r = 4e18, m, q;

    cin >> a >> b >> c >> d;

    while (l <= r) {
        m = (l + r) / 2;

        if (valid(a, b, c, d, m)) {
            r = m - 1;

            q = m;
        }
        else {
            l = m + 1;
        }
    }

    cout << q << "\n";
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