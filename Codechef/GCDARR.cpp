#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 998244353;

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

int W(int l, int r, int m, int n)
{
    int L = lcm(l, r);

    return ((((m / l) - (m / L)) * ((m / r) - (m / L)) % mod) * (bin_exp(m / L, n - 2))) % mod;
}

void solve()
{
    int n, m, l, r, i, j;
    int count = 0;

    cin >> n >> m;

    vector <vector <int> > E(m + 1, vector <int> (m + 1, 0));

    for (l = m; l >= 1; l--) {
        for (r = m; r >= 1; r--) {
            E[l][r] = W(l, r, m, n);

            for (i = 1; i * l <= m; i++) {
                for (j = 1; j * r <= m; j++) {
                    if (!(i == 1 && j == 1)) {
                        E[l][r] = (E[l][r] - E[i * l][j * r]) % mod;
                    }
                }
            }
        }
    }

    for (l = 2; l <= m; l++) {
        for (r = 2; r <= m; r++) {
            if (gcd(l, r) == 1) {
                count = ((count + E[l][r]) % mod + mod) % mod;
            }
        }
    }

    cout << count << "\n";
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