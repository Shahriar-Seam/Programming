#include <bits/stdc++.h>

using namespace std;

#define int long long

string s_m = "1152921504606847061";

__int128_t strto128t(string &s)
{
    __int128_t n = 0;
    
    for (auto &c : s) {
        n = n * 10;
        n += (c - '0');
    }
    
    return n;
}

__int128_t mod = strto128t(s_m);

// https://stackoverflow.com/questions/29388711/how-to-get-the-bit-length-of-an-integer-in-c
// C++ 20
int bit_length(unsigned n)
{
    return 8 * sizeof(n) - __countl_zero(n);
}

// ax + by = gcd(a, b)
// returns gcd(a, b) and calculates x and y
__int128_t extended_euclid(__int128_t a, __int128_t b, __int128_t &x, __int128_t &y)
{
    if (b == 0) {
        x = 1;
        y = 0;

        return a;
    }

    __int128_t x1, y1;
    __int128_t d = extended_euclid(b, a % b, x1, y1);

    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

// x = a^-1 (mod m)
__int128_t inverse_modulo(__int128_t a, __int128_t m = mod)
{
    __int128_t x, y;
    __int128_t g = extended_euclid(a, m, x, y);

    if (g != 1) {
        return -1;
    }

    return (x % m + m) % m;
}

__int128_t fact(int n)
{
    if (n == 0) {
        return 1;
    }
    else {
        return n * fact(n - 1);
    }
}

int C(int n, int k)
{
    return (((fact(n) * inverse_modulo(fact(k))) % mod) * inverse_modulo(fact(n - k))) % mod;
}

void solve()
{
    int n, k, i, j, count = 1;

    cin >> n >> k;

    n = bit_length(n);

    for (i = 2; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (j * 2 + (i - j - 1) + 1 <= k) {
                count += C(i - 1, j);
            }
        }
    }

    if (k >= n) {
        count++;
    }

    cout << (1LL << (n - 1)) - count << "\n";
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

    cout << C(30, 15);

    return 0;
}