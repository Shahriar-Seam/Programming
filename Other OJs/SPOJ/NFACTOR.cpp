#include <bits/stdc++.h>

using namespace std;

#define sz int(1e6 + 5)
vector <bool> marked(sz, false);
vector <int> primes;
vector <int> factors(sz, 0);
vector <vector <int> > factor_count(11, vector <int> (sz + 1, 0));

void sieve()
{
    int i, j;

    for (i = 3; i * i <= sz; i += 2) {
        if (!marked[i]) {
            for (j = i * i; j < sz; j += i + i) {
                marked[j] = true;
            }
        }
    }

    primes.push_back(2);

    for (i = 3; i < sz; i += 2) {
        if (!marked[i]) {
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

    primes.clear();
}

void fill_factor_count()
{
    int i, j;

    for (i = 1; i < sz; i++) {
        for (j = 0; j < 11; j++) {
            factor_count[j][i] = factor_count[j][i - 1];
        }

        factor_count[factors[i]][i]++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    fill_factors();

    fill_factor_count();

    int t, a, b, n;

    cin >> t;

    while (t--) {
        cin >> a >> b >> n;

        cout << factor_count[n][b] - factor_count[n][a - 1] << "\n";
    }

    return 0;
}