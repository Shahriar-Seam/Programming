#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 1e7 + 5;
bitset <sz> marked;
vector <int> primes;

void sieve()
{
    int i, j;

    marked.set();

    for (i = 3; i * i < sz; i += 2) {
        if (marked[i]) {
            for (j = i * i; j < sz; j += 2 * i) {
                marked[j] = false;
            }
        }
    }

    marked[0] = marked[1] = false;
    marked[2] = true;

    for (i = 4; i < sz; i += 2) {
        marked[i] = false;
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

    if (marked[n]) {
        factors.push_back(n);

        return factors;
    }
    
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

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int n, m, a, b, i;
    vector <int> counter(sz, 0);

    cin >> n >> m;

    vector <int> num(n), denom(m);

    for (auto &a : num) {
        cin >> a;

        for (auto &it : get_factors(a)) {
            counter[it]++;
        }
    }

    for (auto &b : denom) {
        cin >> b;

        for (auto &it : get_factors(b)) {
            counter[it]--;
        }
    }

    for (auto &a : num) {
        for (auto &it : get_factors(a)) {
            if (counter[it] <= 0) {
                a /= it;
            }
            else {
                counter[it]--;
            }
        }
    }

    for (auto &b : denom) {
        for (auto &it : get_factors(b)) {
            if (counter[it] >= 0) {
                b /= it;
            }
            else {
                counter[it]++;
            }
        }
    }

    cout << num.size() << " " << denom.size() << "\n";

    for (auto &it : num) {
        cout << it << " ";
    }
    
    cout << "\n";

    for (auto &it : denom) {
        cout << it << " ";
    }

    cout << "\n";

    return 0;
}