#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 1e2 + 5;
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

void solve()
{
    int n, k, i, j;

    cin >> n >> k;

    for (i = n; i > n - 500; i--) {
        for (j = 0; j < primes.size() && primes[j] < i; j++) {
            if (i % primes[j] != 0) {
                if ((i * primes[j] - 1 >= 2 * k) && (abs(i - primes[j]) >= k)) {
                    cout << i << " " << primes[j] << "\n";

                    return;
                }
            }
        }
    }

    cout << "-1 -1\n";
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