#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    vector <int> v(n);
    vector <pair <int, int> > p;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (v[i] < i + 1) {
            p.push_back({v[i], i + 1});
        }
    }

    sort(p.begin(), p.end(), [&] (pair <int, int> a, pair <int, int> b) {
        return a.first < b.first && a.second < b.first;
    });

    for (auto &it : p) {
        cout << it.first << " " << it.second << "\n";
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