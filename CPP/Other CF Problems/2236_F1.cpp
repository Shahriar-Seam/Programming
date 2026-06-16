#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;
const int sz = 5e5 + 5;
vector <int> marked(sz);

void sieve()
{
    int i, j;

    iota(marked.begin(), marked.end(), 0);

    for (i = 4; i < sz; i += 2) {
        marked[i] = 2;
    }

    for (i = 3; i * i < sz; i += 2) {
        if (marked[i] == i) {
            for (j = i * i; j < sz; j += 2 * i) {
                marked[j] = i;
            }
        }
    }
}

void solve()
{
    int n, x, count = 1;

    cin >> n >> x;

    vector <int> v(n);
    unordered_map <int, int> f;

    for (auto &it : v) {
        cin >> it;

        while (it > 1) {
            f[marked[it]]++;

            it /= marked[it];
        }
    }

    for (auto &it : f) {
        count = (count * (it.second + 1)) % mod;
    }

    cout << count << "\n";
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