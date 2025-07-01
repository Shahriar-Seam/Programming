#include <bits/stdc++.h>

using namespace std;

const int sz = 1e5 + 5;
vector <bool> marked(sz, true);
vector <int> min_factor(sz, 1);

void sieve()
{
    int i, j;

    marked[0] = marked[1] = false;

    for (i = 4; i < sz; i += 2) {
        marked[i] = false;

        min_factor[i] = 2;
    }

    for (i = 3; i * i < sz; i += 2) {
        if (marked[i]) {
            for (j = i * i; j < sz; j += 2 * i) {
                if (marked[i]) {
                    marked[j] = false;
                    min_factor[j] = i;
                }
            }
        }
    }
}

void solve()
{
    int n, i;

    cin >> n;

    vector <int> v(n + 1, 0);

    v[1] = 1;

    for (i = (n + 2) / 2; i <= n; i++) {
        if (marked[i]) {
            v[i] = i;
        }
    }

    for (i = n; i > 1; i--) {
        if (marked[i] && v[i] == 0) {
            v[i] = 2 * i;
            v[2 * i] = i;
        }
    }

    for (i = 2; i <= n; i++) {
        if (v[i] == 0) {
            v[i] = v[min_factor[i]];
            v[min_factor[i]] = i;
        }
    }

    for (i = 1; i <= n; i++) {
        cout << v[i] << " ";
    }

    cout << "\n";
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