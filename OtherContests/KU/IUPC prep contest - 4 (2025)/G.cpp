#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int sz = 1e6 + 5;
vector <bool> marked(sz, true);
vector <int> primes;
vector <map <int, int> > factors(sz);

void sieve()
{
    int i, j;

    for (i = 3; i * i < sz; i += 2) {
        if (marked[i]) {
            for (j = i * i; j < sz; j += 2 * i) {
                marked[j] = false;
            }
        }
    }

    primes.push_back(2);

    for (i = 3; i < sz; i += 2) {
        if (marked[i]) {
            primes.push_back(i);
        }
    }
}

void get_factors(int n)
{
    int i, j = 0, temp = n;
    
    while (j < primes.size() && primes[j] * primes[j] <= n) {
        while (n % primes[j] == 0) {
            factors[temp][primes[j]]++;

            n /= primes[j];
        }

        j++;
    }

    if (n > 1) {
        factors[temp][n]++;
    }
}

void fill()
{
    int i;

    for (i = 2; i < sz; i++) {
        get_factors(i);
    }
}

int binary_exponentiation(int b, int p, int m)
{
    long long result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (1LL * result * b) % m;
        }

        b = (1LL * b * b) % m;

        p >>= 1;
    }

    return result % m;
}

void solve()
{
    int n, max_lcm = 1, i;
    map <int, int> f;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        for (auto it : factors[v[i]]) {
            if ((factors[v[i]].size() == 1 && i > 0 && f[it.first] > 0) || ) {
                f[it.first] += it.second - 1;
            }
            else {
                f[it.first] += it.second;
            }
        }
    }

    for (auto it : f) {
        max_lcm = (1LL * max_lcm * binary_exponentiation(it.first, it.second, mod)) % mod;
    }

    cout << max_lcm << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    fill();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}