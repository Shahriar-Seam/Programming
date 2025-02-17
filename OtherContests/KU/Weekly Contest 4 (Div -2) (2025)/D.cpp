#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7;
const int sz = 1e6 + 5;
vector <int> fact(sz);

void factorial()
{
    int i;

    fact[0] = fact[1] = 1;

    for (i = 2; i < sz; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

int euclid(int a, int b, int &x, int &y)
{
    if (!b) {
        return x = 1, y = 0, a;
    }

    int d = euclid(b, a % b, y, x);

    return y -= a / b * x, d;
}

int _inverse(int a)
{
    int inv_a = 1, b = mod, y = 1;

    euclid(a, b, inv_a, y);

    return inv_a;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    factorial();

    int n, m, one, zero, total = 0;

    cin >> n >> m;

    for (one = 1; one <= m; one++) {
        zero = n - one;

        total += (((((fact[n] * _inverse(fact[one])) % mod) * _inverse(fact[zero])) % mod) + mod) % mod;

        total %= mod;
    }

    cout << total << "\n";

    return 0;
}