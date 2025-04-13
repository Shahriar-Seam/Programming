#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j;

    cin >> n;

    vector <vector <int> > v(n, vector <int> (n));
    vector <int> p(2 * n);
    set <int> missing;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    for (i = 1; i <= 2 * n; i++) {
        missing.insert(i);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            p[i + j + 1] = v[i][j];

            if (missing.find(v[i][j]) != missing.end()) {
                missing.erase(v[i][j]);
            }
        }
    }

    p[0] = *missing.begin();

    for (auto it : p) {
        cout << it << " ";
    }

    cout << "\n";
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