#include <bits/stdc++.h>

using namespace std;

const int sz = 1.02e8 + 5;
vector <bool> marked(sz, true);
vector <int> pref(150199428 + 5, 0);
int pref_index = 0;

void to_bin(int n)
{
    int i;

    for (i = 31 - __builtin_clz(n); i >= 0; i--) {
        if (n & (1 << i)) {
            pref[pref_index + 1] = 1 + pref[pref_index];
        }
        else {
            pref[pref_index + 1] = pref[pref_index];
        }

        pref_index++;
    }
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

    to_bin(2);

    for (i = 3; i < sz; i += 2) {
        if (marked[i]) {
            to_bin(i);
        }
    }
}

void solve()
{
    int n;

    cin >> n;

    cout << pref[n] << "\n";
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