#include <bits/stdc++.h>

using namespace std;

#define inf int(1e9)

void solve()
{
    int n, m, i, j;

    cin >> n >> m;

    vector <vector <int> > v(n + 2, vector <int> (m + 2, 0));

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            cin >> v[i][j];
        }
    }
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            v[i][j] = min(v[i][j], max({v[i - 1][j], v[i + 1][j], v[i][j - 1], v[i][j + 1]}));
        }
    }
    
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
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