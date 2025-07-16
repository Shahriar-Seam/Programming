#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, j, count = 0;

    cin >> n;

    vector <pair <int, int> > v(n);
    set <pair <pair <int, int>, pair <int, int> > > s;

    for (i = 0; i < n; i++) {
        cin >> v[i].first;

        v[i].second = i + 1;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        for (j = 0; j < n && v[j].first * v[i].first < 2 * n; j++) {
            if (i == j) {
                continue;
            }
            
            if (v[i].first * v[j].first == v[i].second + v[j].second) {
                if (s.find({v[j], v[i]}) == s.end()) {
                    s.insert({v[i], v[j]});
                }
            }
        }
    }

    cout << s.size() << "\n";
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