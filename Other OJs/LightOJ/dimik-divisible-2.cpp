#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long long a, b, c, i;

    cin >> a >> b >> c;

    long long lcm = (a * b) / __gcd(a, b);

    for (i = lcm; i <= c; i += lcm) {
        cout << i << "\n";
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