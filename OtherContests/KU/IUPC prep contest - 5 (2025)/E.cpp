#include <bits/stdc++.h>

using namespace std;

#define int long long

const int sz = 1e5 + 5;
vector <int> phi(sz), pref(sz);
vector <bool> marked(sz, false);

void sieve_phi()
{
    int i, j;

    for (i = 1; i < sz; i++) {
        phi[i] = i;
    }

    phi[1] = 1;
    marked[1] = true;

    for (i = 2; i < sz; i++) {
        if (!marked[i]) {
            for (j = i; j < sz; j += i) {
                marked[j] = true;

                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }

    for (i = 1, pref[0] = 0; i < sz; i++) {
        pref[i] = pref[i - 1] + phi[i];
    }
}

void solve()
{
    int n;

    cin >> n;

    cout << ((n * (n + 1)) / 2) - pref[n] << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve_phi();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}