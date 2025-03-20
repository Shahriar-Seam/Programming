#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 1e6 + 5;
const int mod = 998244353;

vector <vector <int> > divisors(sz, vector <int> ());
vector <int> phi(sz);
vector <bool> marked(sz, false);

void sieve_phi()
{
    int i, j;

    for (i = 1; i < sz; i++) {
        phi[i] = i;
    }

    phi[1] = 1;
    marked[1] = true;

    for (i = 2; i < sz; i++) {
        if (!marked[i]) {
            for (j = i; j < sz; j += i) {
                marked[j] = true;

                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }
}

void get_divisors()
{
    int i, j;

    for (i = 1; i < sz; i++) {
        for (j = i; j < sz; j += i) {
            divisors[j].push_back(i);
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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    get_divisors();
    sieve_phi();

    int n, sum = 0, q, t, x;

    cin >> n;

    vector <int> v(n), counter(sz, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        for (auto jt : divisors[it]) {
            sum = (sum + phi[jt] * counter[jt]) % mod;

            counter[jt]++;
        }
    }

    cin >> q;

    while (q--) {
        cin >> t >> x;

        if (t == 1) {
            for (auto it : divisors[x]) {
                sum = (sum + (phi[it] * counter[it]) % mod) % mod;

                counter[it]++;
            }

            n++;
        }
        else {
            for (auto it : divisors[x]) {
                counter[it]--;

                sum = (((sum - (phi[it] * counter[it]) % mod) % mod) + mod) % mod;
            }

            n--;
        }

        cout << (sum * inverse_modulo((n * (n - 1)) / 2, mod)) % mod << "\n";
    }

    return 0;
}