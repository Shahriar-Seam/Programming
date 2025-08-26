#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 1e3 + 5;
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

int multiplier(int a, int k, int c)
{
    int g = gcd(k, c);

    if ((-a) % g == 0) {
        int b = ((-a) * inverse_modulo(k, c)) % c;

        if (b < 0) {
            b += c;
        }

        return b;
    }
    else {
        return -1;
    }
}

void solve()
{
    int n, k, i, f;

    cin >> n >> k;

    vector <int> v(n), temp(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto &it : primes) {
        f = 1;

        for (i = 0; i < n; i++) {
            temp[i] = multiplier(v[i], k, it);

            if (temp[i] < 0 || temp[i] > k) {
                f = 0;

                break;
            }
        }

        if (f) {
            for (i = 0; i < n; i++) {
                cout << v[i] + k * temp[i] << " ";
            }

            cout << "\n";

            return;
        }
    }
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