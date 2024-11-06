#include <bits/stdc++.h>

using namespace std;

#define sz int(5e5 + 5)
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int i, j = 0;
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

long long binary_exponentiation(long long b, long long p)
{
    long long result = 1;

    while (p > 0) {
        if (p & 1) {
            result = result * b;
        }

        b = b * b;

        p >>= 1;
    }

    return result;
}

void solve()
{
    long long n;
    long long sum = 1, temp;

    cin >> n;

    map <int, int> factors = get_factors(n);

    for (auto it : factors) {
        temp = 1;

        while (it.second > 0) {
            temp += binary_exponentiation(it.first, it.second);

            it.second--;
        }

        sum *= temp;
    }

    sum -= n;

    cout << sum << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}