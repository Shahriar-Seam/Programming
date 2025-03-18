#include <bits/stdc++.h>

using namespace std;

#define int long long
const int sz = 1e6 + 5;
const int mod = 998244353;

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

map <int, int> get_factors(int n)
{
    int j = 0;
    map <int, int> factors;
    
    while (j < primes.size() && primes[j] * primes[j] <= n) {
        while (n % primes[j] == 0) {
            factors[primes[j]]++;

            n /= primes[j];
        }

        j++;
    }

    if (n > 1) {
        factors[n]++;
    }

    return factors;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n, i;

    cin >> n;

    vector <int> p(n), e(n);

    for (auto &it : p) {
        cin >> it;
    }

    for (auto &it : e) {
        cin >> it;
    }

    vector <int> counter(sz, 0);

    for (i = 0; i < n; i++) {
        counter[p[i]] = e[i];
    }

    for (i = primes.size() - 1; i > 0; i--) {
        if (counter[primes[i]] > 0) {
            map <int, int> factors = get_factors(primes[i] - 1);

            for (auto it : factors) {
                counter[it.first] = (counter[it.first] + counter[primes[i]] * it.second) % mod;
            }
        }
    }

    cout << counter[2] + (find(p.begin(), p.end(), 2) == p.end()) << "\n";

    return 0;
}