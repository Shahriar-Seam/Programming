#include <bits/stdc++.h>

using namespace std;

#define sz (int) (5e6 + 5)
vector <int> phi(sz);
vector <unsigned long long> pref(sz + 1, 0);
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

    marked.clear();

    for (i = 0; i < sz; i++) {
        pref[i + 1] = pref[i] + (1LL * phi[i] * phi[i]);
    }

    phi.clear();
}

void solve()
{
    int a, b;

    cin >> a >> b;

    unsigned long long score = pref[b + 1] - pref[a];

    cout << score << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve_phi();

    int t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";
        solve();
    }

    return 0;
}