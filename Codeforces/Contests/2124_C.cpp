#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 4e4 + 5;
vector <bool> marked(sz, true);
vector <int> primes;

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

map <int, int> count_divisor(int n)
{
    int divisor = 1, i, cnt;
    map <int, int> mp;

    for (i = 0; primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            cnt = 0;

            while (n % primes[i] == 0) {
                n /= primes[i];
                cnt++;
            }

            mp[primes[i]] = cnt;
        }
    }

    if (n > 1) {
        mp[n]++;
    }

    return mp;
}

int binary_exponentiation(int b, int p, int m = 1e9 + 7)
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
    int n, i, x = 1;
    set <int> s;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = n - 2; i >= 0; i--) {
        if (v[i + 1] % v[i] != 0) {
            s.insert(v[i] / gcd(v[i], v[i + 1]));

            v[i] = gcd(v[i], v[i + 1]);
        }
    }

    for (auto &jt : s) {
        for (auto &it : count_divisor(jt)) {
            mp[it.first] = max(mp[it.first], it.second);
        }
    }

    for (auto &it : mp) {
        x *= binary_exponentiation(it.first, it.second);
    }

    cout << x << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}