#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, p, j;

    cin >> n;

    vector <int> x(n), y(n), temp_y(n);
    vector <pair <int, int> > l(n);

    for (auto &it : x) {
        cin >> it;
    }

    for (auto &it : y) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        p = x[i];

        for (j = 0; j < n; j++) {
            l[j] = {abs(x[j] - p), x[j]};
        }

        sort(l.begin(), l.end());

        for (j = 0; j < n; j++) {
            temp_y[j] = l[j].second;
        }

        if (temp_y == y) {
            cout << i + 1 << "\n";

            return;
        }
    }

    cout << -1 << "\n";
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