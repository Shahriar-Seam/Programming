#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;

    cin >> n >> k;

    vector <pair <int, pair <int, int> > > v(n);

    for (auto &it : v) {
        cin >> it.first >> it.second.first >> it.second.second;
    }

    sort(v.begin(), v.end());

    for (auto &it : v) {
        if (k >= it.first && k <= it.second.first && k < it.second.second) {
            k = it.second.second;
        }
    }

    cout << k << "\n";
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