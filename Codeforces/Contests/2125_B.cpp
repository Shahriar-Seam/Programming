#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int a, b, k, g;

    cin >> a >> b >> k;

    g = gcd(a, b);

    a /= g;
    b /= g;

    if (a <= k && b <= k) {
        cout << 1 << "\n";
    }
    else {
        cout << 2 << "\n";
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