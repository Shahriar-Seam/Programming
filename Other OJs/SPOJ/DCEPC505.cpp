#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 5.5e6 + 5;
const int N = 1.1e7 + 5;
vector <bool> marked(sz, true);
vector <int> primes, four_divs;

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

void fill()
{
    int i, j;

    for (i = 0; i < primes.size(); i++) {
        for (j = i + 1; j < primes.size(); j++) {
            if (primes[i] * primes[j] < N) {
                four_divs.push_back(primes[i] * primes[j]);
            }
            else {
                break;
            }
        }
    }

    sort(four_divs.begin(), four_divs.end());
}

void solve()
{
    int k;

    cin >> k;

    cout << four_divs[k - 1] << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    fill();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}