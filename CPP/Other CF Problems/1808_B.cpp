#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, m, i, j;
    int s = 0, sum = 0;

    cin >> n >> m;

    vector <vector <int> > v(m, vector <int> (n));

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> v[j][i];
        }
    }

    for (j = 0; j < m; j++) {
        sort(v[j].begin(), v[j].end(), greater <> ());
    }

    if (n == 1) {
        cout << 0 << "\n";

        return;
    }

    for (j = 0; j < m; j++) {
        s = 0;

        for (i = 0; i < n; i++) {
            s += v[j][i] * i;
        }

        sum -= s;

        reverse(v[j].begin(), v[j].end());

        s = 0;

        for (i = 0; i < n; i++) {
            s += v[j][i] * i;
        }

        sum += s;
    }

    cout << sum << "\n";
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