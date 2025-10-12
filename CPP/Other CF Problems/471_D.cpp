#include <bits/stdc++.h>

using namespace std;

string s_x = "1152921504606846989";
string s_m = "1152921504606847061";

__int128_t x;
__int128_t mod;
__int128_t inv_x;

__int128_t strto128t(string &s)
{
    __int128_t n = 0, i;

    for (i = 0; i < s.size(); i++) {
        n *= 10;
        n += s[i] - '0';
    }

    return n;
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
__int128_t inverse_modulo(__int128_t a, __int128_t m)
{
    __int128_t x, y;
    __int128_t g = extended_euclid(a, m, x, y);

    if (g != 1) {
        return -1;
    }

    return (x % m + m) % m;
}

__int128_t _hash(vector <__int128_t> v)
{
    __int128_t h = 0, i, xx = 1;

    for (i = 0; i < v.size(); i++) {
        h = ((h + v[i] * xx) % mod + mod) % mod;

        xx = ((xx * x) % mod + mod) % mod;
    }

    return h;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, w, temp_val, count = 0;
    __int128_t i, b0;
    __int128_t h_a, h_b, xx = 1, val = 0;

    x = strto128t(s_x);
    mod = strto128t(s_m);
    inv_x = inverse_modulo(x, mod);

    cin >> n >> w;

    vector <__int128_t> a(n), b(w), temp;

    for (auto &it : a) {
        cin >> temp_val;

        it = temp_val;
    }

    for (auto &it : b) {
        cin >> temp_val;

        it = temp_val;
    }

    if (w > n) {
        cout << 0 << "\n";

        return 0;
    }

    for (i = 0; i < w; i++) {
        val = (val + xx) % mod;

        xx = (xx * x) % mod;
    }

    xx = (xx * inv_x) % mod;

    for (i = 0, b0 = b[0]; i < w; i++) {
        b[i] -= b0;
    }

    for (i = 0; i < w; i++) {
        temp.push_back(a[i]);
    }

    h_a = (_hash(temp) + mod) % mod;
    h_b = (_hash(b) + mod) % mod;

    if (((h_a - a[0] * val) % mod + mod) % mod == h_b) {
            count++;
    }

    for (i = w; i < n; i++) {
        h_a -= a[i - w];
        h_a = (h_a * inv_x) % mod;
        h_a = (h_a + a[i] * xx) % mod;

        h_a = (h_a + mod) % mod;

        if (((h_a - a[i - w + 1] * val) % mod + mod) % mod == h_b) {
                count++;
        }
    }

    cout << count << "\n";

    return 0;
}