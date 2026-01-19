#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    vector <pair <int, int> > v(n);

    for (i = 0; i < n; i++) {
        cin >> v[i].first;

        v[i].second = i % 2;
    }

    sort(v.begin(), v.end());

    for (i = 1; i < n; i++) {
        if (v[i].second == v[i - 1].second) {
            cout << "NO\n";

            return;
        }
    }

    cout << "YES\n";
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