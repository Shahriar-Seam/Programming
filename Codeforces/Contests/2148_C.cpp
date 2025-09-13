#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, m, points = 0, i;

    cin >> n >> m;

    vector <pair <int, int> > v(n);

    for (auto &it : v) {
        cin >> it.first >> it.second;
    }

    v.insert(v.begin(), {0, 0});

    for (i = 1; i <= n; i++) {
        if ((v[i].first - v[i - 1].first) & 1) {
            if (v[i].second != v[i - 1].second) {
                points += v[i].first - v[i - 1].first;
            }
            else {
                points += v[i].first - v[i - 1].first - 1;
            }
        }
        else {
            if (v[i].second == v[i - 1].second) {
                points += v[i].first - v[i - 1].first;
            }
            else {
                points += v[i].first - v[i - 1].first - 1;
            }
        }
    }

    points += m - v[n].first;

    cout << points << "\n";
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