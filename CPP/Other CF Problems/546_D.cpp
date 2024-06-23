#include <bits/stdc++.h>

using namespace std;

int max_size = 5000005;
vector <int> primes;
vector <int> divisors;
vector <int> prefix;

void sieve()
{
    int i, j;

    primes.resize(max_size);

    for (i = 1; i < max_size; i += 2) {
        primes[i] = i;
        primes[i - 1] = 2;
    }

    primes[0] = 1;

    for (i = 3; i * i <= max_size; i += 2) {
        if (primes[i] == i) {
            for (j = i * i; j < max_size; j += i + i) {
                if (primes[j] == j) {
                    primes[j] = i;
                }
            }
        }
    }
}

void number_of_prime_factors()
{
    int i, n, cnt;

    divisors.resize(max_size);

    for (i = 1; i < max_size - 1; i++) {
        n = i;
        cnt = 0;

        while (primes[n] != 1) {
            n /= primes[n];
            cnt++;
        }

        divisors[i] = cnt;
    }
}

void fill_prefix()
{
    int i;

    prefix.resize(max_size);
    prefix[0] = prefix[1] = 0;

    for (i = 2; i < max_size - 1; i++) {
        prefix[i] = prefix[i - 1] + divisors[i];
    }
}

void solve()
{
    int a, b;

    cin >> a >> b;

    cout << prefix[a] - prefix[b] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    number_of_prime_factors();
    fill_prefix();

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}