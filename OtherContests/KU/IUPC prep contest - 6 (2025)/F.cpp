#include <bits/stdc++.h>

using namespace std;

const int sz = 2.5e8 + 5;
int phi[sz], inv_phi[sz];
bitset <sz> marked;

void sieve_phi()
{
    int i, j;

    for (i = 0; i < sz; i++) {
        phi[i] = i;

        inv_phi[i] = -1;
    }

    phi[1] = 1;
    marked[1] = 1;

    for (i = 2; i < sz; i++) {
        if (!marked[i]) {
            for (j = i; j < sz; j += i) {
                marked[j] = 1;

                phi[j] = phi[j] / i * (i - 1);
            }
        }
    }

    for (i = sz - 1; i >= 0; i--) {
        inv_phi[phi[i]] = i;
    }
}

void solve()
{
    int n;

    cin >> n;

    cout << inv_phi[n] << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve_phi();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}