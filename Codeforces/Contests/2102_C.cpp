#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    int l, r, u, d;
    int i, j, k = 0;

    cin >> n;

    vector <vector <int> > v(n, vector <int> (n, 0));

    l = r = u = d = (n - 1) / 2;

    while (l >= 0 && r < n && u >= 0 && d < n) {
        for (j = l, i = u; j <= r; j++) {
            v[i][j] = k++;
        }

        r++;

        if (r < n) {
            for (j = r, i = u; i <= d; i++) {
                v[i][j] = k++;
            }

            d++;
        }

        if (r < n && d < n) {
            for (j = r, i = d; j >= l; j--) {
                v[i][j] = k++;
            }

            l--;
        }

        if (r < n && d < n && l >= 0) {
            for (j = l, i = d; i >= u; i--) {
                v[i][j] = k++;
            }

            u--;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }

        cout << "\n";
    }
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