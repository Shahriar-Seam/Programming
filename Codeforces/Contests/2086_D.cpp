#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 26 * 5e5 + 5;
const int mod = 998244353;
vector <int> fact(sz);

void factorial()
{
    int i;

    fact[0] = fact[1] = 1;

    for (i = 2; i < sz; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

// ax + by = gcd(a, b)
// returns gcd(a, b) and calculates x and y
int extended_euclid(int a, int b, int &x, int &y)
{
    if (b == 0) {
        x = 1;
        y = 0;

        return a;
    }

    int x1, y1;
    int d = extended_euclid(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

// x = a^-1 (mod m)
int inverse_modulo(int a, int m)
{
    int x, y;
    int g = extended_euclid(a, m, x, y);

    if (g != 1) {
        return -1;
    }

    return (x % m + m) % m;
}

void solve()
{
    int n, i, single = 0, odd, even, comb;
    vector <int> c(26, 0);
    int count = 1;

    for (auto &it : c) {
        cin >> it;
    }

    // sort(c.begin(), c.end(), greater <int> ());

    n = accumulate(c.begin(), c.end(), 0LL);

    for (i = 0; i < 26; i++) {
        if (c[i] == 1) {
            single++;
        }
        else if (c[i] > 1) {
            odd = (n + 1) / 2;
            even = n / 2;

            
            comb = 0;
            
            if (odd >= c[i]) {
                comb = (fact[odd] * inverse_modulo(fact[c[i]], mod)) % mod;
            }
            if (even >= c[i]) {
                comb = (comb + (fact[even] * inverse_modulo(fact[c[i]], mod)) % mod) % mod;
            }
            
            count = (count * comb) % mod;

            n -= c[i];
        }
    }

    count = (count * fact[single]) % mod;

    cout << count << "\n";
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