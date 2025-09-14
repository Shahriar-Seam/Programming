#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int sz = 1e3 + 5;
int fact[sz];

void factorial()
{
    int i;

    fact[0] = fact[1] = 1;

    for (i = 2; i < sz; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

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

// x = a^-1 (mod m)
int inv(int a, int m = mod)
{
    return bin_exp(a, m - 2);
}

int nCr(int n, int r)
{
    return (((fact[n] * inv(fact[r])) % mod) * inv(fact[n - r])) % mod;
}

void solve()
{
    int n, k;
    map <int, int, greater <> > mp;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        mp[it]++;
    }

    for (auto &it : mp) {
        if (it.second < k) {
            k -= it.second;
        }
        else {
            cout << nCr(it.second, k) << "\n";

            return;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    factorial();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}