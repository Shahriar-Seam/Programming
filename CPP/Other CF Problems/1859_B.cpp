#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, m, i, j, f = 0;
    int max_beauty = 0;

    cin >> n;

    vector <vector <int> > v(n);
    vector <int> bamboo;

    for (i = 0; i < n; i++) {
        cin >> m;

        v[i].resize(m);

        for (j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    for (i = 0; i < n; i++) {
        sort(v[i].begin(), v[i].end());
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        bamboo.push_back(v[i][1]);
    }

    sort(bamboo.begin(), bamboo.end(), greater <int> ());

    cout << v[0][0] + accumulate(bamboo.begin(), bamboo.begin() + n - 1, 0LL) << "\n";
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