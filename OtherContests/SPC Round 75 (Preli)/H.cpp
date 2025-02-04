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

int legendres(int n, int p)
{
    int result = 0;

    while (n > 0) {
        n /= p;
        result += n;
    }

    return result;
}

bool possible(map <int, int> &mp, int m)
{
    for (auto it : mp) {
        if (legendres(m, it.first) < it.second) {
            return false;
        }
    }

    return true;
}

void solve()
{
    int n, i, j, min_n;
    vector <int> f;
    map <int, int> mp;

    cin >> n;

    f = get_factors(n);

    for (auto it : f) {
        mp[it]++;
    }

    int l = 0, r = 1e6, mid;

    while (l <= r) {
        mid = (l + r) / 2;

        if (possible(mp, mid)) {
            min_n = mid;

            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << min_n << "\n";
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