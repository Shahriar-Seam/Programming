#include <bits/stdc++.h>

using namespace std;

#define int long long
const int sz = 1e6 + 5;
const int mod = 998244353;
vector <int> _phi(sz);
vector <bool> marked(sz, false);
vector <int> counter(sz, 0);
int inv[sz + 1] = {};

int binary_exponentiation(int b, int p)
{
    int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = (result * b) % mod;
        }

        b = (b * b) % mod;

        p >>= 1;
    }

    return result;
}

// https://cp-algorithms.com/algebra/phi-function.html
int phi(int p, int e)
{
    int power = binary_exponentiation(p, e - 1);

    return power * p - power;
}

void sieve_phi()
{
    int i, j;

    for (i = 1; i < sz; i++) {
        _phi[i] = i;
    }

    _phi[1] = 1;
    marked[1] = true;

    for (i = 2; i < sz; i++) {
        if (!marked[i]) {
            for (j = i; j < sz; j += i) {
                marked[j] = true;

                _phi[j] = _phi[j] / i * (i - 1);
            }
        }
    }
}

int fill_counter(int n)
{
    if (n <= 2) {
        return 1;
    }

    if (counter[n] == 0) {
        counter[n] = 1 + fill_counter(_phi[n]);
    }

    return counter[n];
}

// https://cp-algorithms.com/algebra/module-inverse.html
void inverse_mod(int m)
{
    inv[1] = 1;

    for(int a = 2; a < sz; ++a) {
        inv[a] = m - (long long)(m/a) * inv[m%a] % m;
    }
}

// phi(p, e) = exp(p, e - 1) * (p - 1)
// phi(phi(p, e)) = phi(p, e - 1) * phi(p - 1)
int count_to_1(int p, int e)
{
    int count = 1, c = counter[p], ph = phi(p, e), i;
    // vector <int> v;

    // cout << ph << "\n";

    for (i = 1; ph > 1 && i <= e && i <= p; i++) {
        c = max(c, 1 + counter[p - i]);

        ph = ph / inv[p] * (p - i);

        count++;

        // cout << ph << "\n";
    }

    // for (i = 0; i < v.size(); i++) {
    //     c = 1;

    //     while (v[i] != 1) {
    //         // cout << _phi[v[i]] << "\n";

    //         c++;

    //         v[i] = _phi[v[i]];
    //     }

    //     count = max(count, c);
    // }

    count = max(count, c);

    return count;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve_phi();
    inverse_mod(mod);

    int n, count = 1, i;

    cin >> n;

    vector <int> p(n), e(n);

    for (auto &it : p) {
        cin >> it;
    }

    for (auto &it : e) {
        cin >> it;
    }

    for (i = 1; i < sz; i++) {
        fill_counter(i);
    }

    for (i = 0; i < n; i++) {
        // count = max(count, count_to_1(p[i], e[i]));

        // cout << p[i] << " " << count_to_1(p[i], e[i]) << "\n";
    }

    // cout << count << "\n";

    // cout << counter[12] << "\n";

    cout << _phi[24] << "\n";
    cout << _phi[_phi[24]] << "\n";
    cout << _phi[_phi[_phi[24]]] << "\n";
    cout << _phi[_phi[_phi[_phi[24]]]] << "\n";

    return 0;
}