#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 1e6 + 5;
vector <bool> marked(sz, true);
set <int> primes;

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

    primes.insert(2);

    for (i = 3; i < sz; i += 2) {
        if (marked[i]) {
            primes.insert(i);
        }
    }
}

void solve()
{
    int d, a, b;

    cin >> d;

    a = *primes.upper_bound(d);
    b = *primes.upper_bound(a + d - 1);

    cout << a * b << "\n";
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