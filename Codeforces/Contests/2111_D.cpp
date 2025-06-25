#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i, j = -1;

    cin >> n >> m;

    vector <int> v(m);
    vector <vector <int> > c(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            j++;

            j %= m;
        }

        if (i % 2 == 0) {
            c[i].push_back(v[j]);
            c[i].push_back(v[m - j - 1]);
            c[i].push_back(v[j]);
            c[i].push_back(v[m - j - 1]);
            c[i].push_back(v[j]);
            c[i].push_back(v[m - j - 1]);
        }
        else {
            c[i].push_back(v[m - j - 1]);
            c[i].push_back(v[j]);
            c[i].push_back(v[m - j - 1]);
            c[i].push_back(v[j]);
            c[i].push_back(v[m - j - 1]);
            c[i].push_back(v[j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < 6; j++) {
            cout << c[i][j] << " ";
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