#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

void solve()
{
    int n;

    cin >> n;

    n = 2 * n - 2;

    // https://oeis.org/A002623
    int num = (((__int128_t) (n + 2) * (n + 4) * (2 * n + 3)) / 24) % mod;

    cout << (num * 2022) % mod << "\n";
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