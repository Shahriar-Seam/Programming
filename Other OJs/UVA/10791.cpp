#include <bits/stdc++.h>

using namespace std;

#define int long long
const int sz = 32000;
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

int binary_exponentiation(int b, int p)
{
    int result = 1;

    while (p > 0) {
        if (p & 1) {
            result = result * b;
        }

        b = b * b;

        p >>= 1;
    }

    return result;
}

void solve(int n)
{
    map <int, int> factors = get_factors(n);
    int sum = 0;

    if (n == 1) {
        sum = 2;
    }

    if (factors.size() == 1) {
        sum = 1;
    }

    for (auto it : factors) {
        sum += binary_exponentiation(it.first, it.second);
    }

    cout << sum << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int32_t t, i, n;

    for (i = 1; ; i++) {
        cin >> n;
        
        if (n == 0) {
            break;
        }

        cout << "Case " << i << ": ";

        solve(n);
    }

    return 0;
}