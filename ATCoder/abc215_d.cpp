#include <bits/stdc++.h>

using namespace std;

const int sz = 1e5 + 5;
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
    int i, j;

    for (i = 0; i < primes.size(); i++) {
        for (j = primes[i]; j < sz; j += primes[i]) {
            factors[j].push_back(primes[i]);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();
    get_factors();

    int n, m, i, f;
    map <int, int> mp;

    cin >> n >> m;

    vector <int> v(n), k;

    for (auto &it : v) {
        cin >> it;

        for (auto jt : factors[it]) {
            mp[jt]++;
        }
    }

    for (i = 1; i <= m; i++) {
        f = 1;

        for (auto it : factors[i]) {
            if (mp[it] > 0) {
                f = 0;

                break;
            }
        }

        if (f) {
            k.push_back(i);
        }
    }

    cout << k.size() << "\n";

    for (auto it : k) {
        cout << it << "\n";
    }

    return 0;
}