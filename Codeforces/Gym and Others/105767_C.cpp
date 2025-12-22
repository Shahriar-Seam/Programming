#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7;

int bin_exp(int b, int p, int m = mod)
{
    int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (result * b) % m;
        }

        b = (b * b) % m;

        p >>= 1;
    }

    return result % m;
}

void solve()
{
    int k, n, sum = 0;

    cin >> k >> n;

    vector <int> v(n + 1);

    for (auto &it : v) {
        cin >> it;

        sum += it;
    }

    sum = (sum % mod + mod) % mod;

    cout << (bin_exp(sum, k) + mod) % mod << "\n";
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