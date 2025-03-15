#include <bits/stdc++.h>

using namespace std;

#define sz int(1e6 + 5)
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

vector <int> get_factors(int n)
{
    int i, j = 0;
    vector <int> factors;
    
    while (j < primes.size() && primes[j] * primes[j] <= n) {
        while (n % primes[j] == 0) {
            factors.push_back(primes[j]);

            n /= primes[j];
        }

        j++;
    }

    if (n > 1) {
        factors.push_back(n);
    }

    return factors;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n, k;

    cin >> n >> k;

    vector <int> factors = get_factors(n);

    if (factors.size() < k) {
        cout << -1 << "\n";
    }
    else {
        for (auto it : factors) {
            if (k == 1) {
                break;
            }

            cout << it << " ";

            k--;

            n /= it;
        }

        cout << n << "\n";
    }

    return 0;
}