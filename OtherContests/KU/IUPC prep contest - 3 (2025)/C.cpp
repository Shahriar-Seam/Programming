#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int binary_exponentiation(int b, int p)
{
    int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (1LL * result * b) % mod;
        }

        b = (1LL * b * b) % mod;

        p >>= 1;
    }

    return result % mod;
}

void solve()
{
    int a, b;

    cin >> a >> b;

    cout << binary_exponentiation(a, b) << "\n";
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