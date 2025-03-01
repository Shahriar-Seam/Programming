#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, k;

    cin >> n >> k;

    cout << ((n % gcd(2, k) == 0) ? "YES" : "NO") << "\n";
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