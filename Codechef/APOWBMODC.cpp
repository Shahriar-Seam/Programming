#include <bits/stdc++.h>

using namespace std;

vector <int> primes;
int max_size = 100000;

void sieve()
{
    int i, j;
    bool marked[max_size] = {};

    marked[0] = marked[1] = true;

    for (i = 3; i * i <= max_size; i += 2) {
        if (marked[i] == false) {
            for (j = i * i; j <= max_size; j += i + i) {
                marked[j] = true;
            }
        }
    }

    primes.push_back(2);

    for (i = 3; i < max_size; i += 2) {
        if (marked[i] == false) {
            primes.push_back(i);
        }
    }
}

set <int> find_2_smallest_factor(long long n)
{
    int i, p;
    set <int> factors;

    for (i = 0; i < primes.size(); i++) {
        if (n % primes[i] == 0) {
            p = primes[i];

            factors.insert(p);

            if (factors.size() == 2) {
                return factors;
            }

            while (n % p == 0) {
                n /= p;
            }
        }
    }

    return factors;
}

void solve()
{
    long long a;

    cin >> a;

    set <int> factors = find_2_smallest_factor(a);

    if (factors.size() == 2) {
        for (auto it : factors) {
            cout << 1LL * it * a << " ";
        }

        cout << "\n";
    }
    else {
        cout << 2 * a << " " << a * a << "\n";
    }
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