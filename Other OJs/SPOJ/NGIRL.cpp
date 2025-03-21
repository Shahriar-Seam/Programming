#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 1e5 + 500;
vector <bool> marked(sz, true);
vector <int> sq_primes;

int max(int a, int b)
{
    return a > b ? a : b;
}

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

    sq_primes.push_back(4);

    for (i = 3; i < sz; i += 2) {
        if (marked[i]) {
            sq_primes.push_back(i * i);
        }
    }
}

int left_bound(int k)
{
    int l = 0, r = sq_primes.size() - 1, m, index = -1;

    while (l <= r) {
        m = (l + r) / 2;

        if (sq_primes[m] > k) {
            index = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    return index;
}

int right_bound(int k)
{
    int l = 0, r = sq_primes.size() - 1, m, index = -1;

    while (l <= r) {
        m = (l + r) / 2;

        if (sq_primes[m] <= k) {
            index = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    return index;
}

void solve()
{
    int n, k, l, r;

    cin >> n >> k;

    l = left_bound(k);
    r = right_bound(n);

    cout << r + 1 << " " << max(0, r - l + 1) << "\n";
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