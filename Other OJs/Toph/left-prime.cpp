#include <bits/stdc++.h>

using namespace std;

const int sz = 1e7 + 5;
vector <bool> marked(sz, true);
vector <int> primes(sz, 0);

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

    primes[2] = 1;

    for (i = 3; i < sz; i += 2) {
        if (marked[i]) {
            primes[i] = 1;
        }
    }

    for (i = 1; i < sz; i++) {
        primes[i] += primes[i - 1];
    }
}

void solve()
{
    int n;

    cin >> n;

    cout << primes[n - 1] << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}