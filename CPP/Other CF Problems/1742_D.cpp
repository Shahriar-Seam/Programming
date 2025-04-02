#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, ij = -1;

    cin >> n;

    vector <int> v(n), indices(1001, 0);

    for (i = 0; i < n; i++) {
        cin >> v[i];

        indices[v[i]] = i + 1;
    }

    for (i = 1; i <= 1000; i++) {
        for (j = 1; j <= 1000; j++) {
            if (indices[i] && indices[j] && gcd(i, j) == 1) {
                ij = max(ij, indices[i] + indices[j]);
            }
        }
    }

    cout << ij << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}