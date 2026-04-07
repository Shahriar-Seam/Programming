#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 2e4 + 5;
map <__int128_t, int> mp;
vector <__int128_t> p;
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

void fill()
{
    int i, j, f;
    __int128_t start = 6;

    p.push_back(1);
    p.push_back(3);

    for (i = 0, j = 1; i < sz; ) {
        if (i > 0) {
            start = primes[j - 1] * primes[j - 1] * primes[j];
            
            p.push_back(start);
            i++;
        }


        start = primes[j++] * 2;

        while (i < sz && start * 2 * primes[j - 1] < 1e16) {
            p.push_back(start);

            start *= 2;
            i++;
        }

        p.push_back(start * primes[j - 1]);

        i++;
    }
}

void solve()
{
    int n, i;

    cin >> n;

    for (i = 0; i < n; i++) {
        cout << (long long) p[i] << " ";
    }

    cout << "\n";
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