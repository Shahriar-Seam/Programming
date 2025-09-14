#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int sz = 1e6 + 5;
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

// solve ax + by = c, x + y = n
void solve(int a, int b, int c, int n, int &x, int &y)
{
    if ((a * n - c) % (a - b) == 0) {
        y = (a * n - c) / (a - b);
        x = n - y;
    }
    else {
        x = -1;
        y = -1;
    }

    if (x < 0 || y < 0) {
        x = -1;
        y = -1;
    }
}

int single(int n, int x, int y)
{
    if (x < 0 || y < 0) {
        return 0;
    }

    return (((fact[n] * inv(fact[x])) % mod) * inv(fact[y])) % mod;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    factorial();

    int a, b, n, x, y, sum = 0;
    int i, mask, d;
    string s;

    cin >> a >> b >> n;

    if (a < b) {
        swap(a, b);
    }

    for (d = 1; d < 8; d++) {
        for (mask = 0; mask < (1 << d); mask++) {
            s = string(d, 0);

            for (i = 0; i < d; i++) {
                if (mask & (1 << i)) {
                    s[i] = a + '0';
                }
                else {
                    s[i] = b + '0';
                }
            }

            solve(a, b, stoll(s), n, x, y);

            sum = (sum + single(n, x, y)) % mod;
        }
    }

    cout << sum << "\n";

    return 0;
}