#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int a, b, max_gcd;

    cin >> a >> b;

    max_gcd = abs(a - b);

    if (max_gcd == 0) {
        cout << 0 << " " << 0 << "\n";
    }
    else {
        cout << max_gcd << " " << min(a % max_gcd, max_gcd - a % max_gcd) << "\n";
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