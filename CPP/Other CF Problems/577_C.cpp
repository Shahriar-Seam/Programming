#include <bits/stdc++.h>

using namespace std;

const int sz = 1e3 + 15;
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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n, i, p;
    vector <int> v;

    cin >> n;

    for (i = 0; primes[i] <= n; i++) {
        p = primes[i];

        while (p <= n) {
            v.push_back(p);

            p *= primes[i];
        }
    }

    cout << v.size() << "\n";

    for (auto &it : v) {
        cout << it << " ";
    }

    cout << "\n";

    return 0;
}