#include <bits/stdc++.h>

using namespace std;

#define int long long
const int sz = 1e6 + 5;
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

int is_prime(int n)
{
    int i;

    if (n == 1) {
        return 0;
    }

    for (i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            return 0;
        }
    }

    return 1;
}

int clean(int n)
{
    int i;

    for (i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
        if (n % primes[i] == 0) {
            while (n % primes[i] == 0) {
                n /= primes[i];
            }
        }
    }

    return n;
}

int count_f(int n)
{
    int i, count = 0, p, last = 1;
    set <int> s;

    for (i = 0; i < primes.size() && primes[i] * primes[i] <= n; i++) {
        p = primes[i];

        while (n % p == 0) {
            n /= p;

            s.insert(p);

            count++;

            p *= primes[i];
        }
    }

    if (is_prime(clean(n)) && (s.find(n) == s.end())) {
        count++;
    }

    return count;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n;

    cin >> n;

    cout << count_f(n) << "\n";

    return 0;
}