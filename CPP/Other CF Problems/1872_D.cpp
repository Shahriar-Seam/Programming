#include <bits/stdc++.h>

using namespace std;

#define int long long

int sum(int n)
{
    return (n * (n + 1)) / 2;
}

void solve()
{
    int n, x, y, lcm, i, j;
    int a = 0, b = 0;

    cin >> n >> x >> y;

    lcm = (x * y) / gcd(x, y);

    a = n / x - n / lcm;
    b = n / y - n / lcm;

    cout << sum(n) - sum(n - a) - sum(b) << "\n";
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