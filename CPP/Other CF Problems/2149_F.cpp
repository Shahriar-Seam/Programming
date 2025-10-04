#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int h, d, n;

    cin >> h >> d;

    h--;

    n = (-1 + sqrt(1LL + 8 * h)) / 2;

    h -= (n * (n + 1)) / 2;
    d -= n;

    cout << (h <= 1) + n + (2 * d - 1) << "\n";
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