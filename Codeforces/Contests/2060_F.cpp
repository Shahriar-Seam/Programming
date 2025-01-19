#include <bits/stdc++.h>

using namespace std;

#define sz int(1e5 + 5)
vector <bool> marked(sz, true);
vector <int> primes;
vector <vector <int> > factors(sz, vector <int> ());

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

void get_factors()
{
    int i, j, temp;

    for (auto it : primes) {
        for (j = it; j < sz; j += it) {
            temp = j;

            while (temp % it == 0) {
                factors[j].push_back(it);

                temp /= it;
            }
        }
    }
}

void solve()
{
    int n, k;
    int x, factor_count, rem;

    cin >> k >> n;

    for (x = 1; x <= k; x++) {
        factor_count = factors[x];
        rem = n - factor_count;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    get_factors();

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    // for (int i = 0; i < 11; i++) {
    //     cout << i << ": ";

    //     for (auto it : factors[i]) {
    //         cout << it << " ";
    //     }

    //     cout << "\n";
    // }

    return 0;
}