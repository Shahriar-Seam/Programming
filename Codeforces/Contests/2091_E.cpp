#include <bits/stdc++.h>

using namespace std;

const int sz = 1e7 + 5;
vector <bool> marked(sz, true);
vector <int> primes;
vector <int> factors(sz, 0);
vector <int> pref(sz + 1, 0);

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

void fill_factors()
{
    int i, j;

    for (i = 0; i < primes.size(); i++) {
        for (j = primes[i]; j < sz; j += primes[i]) {
            factors[j]++;
        }
    }

    for (i = 0; i < sz; i++) {
        pref[i + 1] = pref[i] + factors[i];
    }
}

void solve()
{
    int n;

    cin >> n;

    cout << pref[n + 1] << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    fill_factors();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}