#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, temp = 0;

    cin >> n;

    vector <pair <int, int> > v(n), ops;
    map <pair <int, int>, int> mp;

    for (auto &it : v) {
        cin >> it.first;
    }

    for (auto &it : v) {
        cin >> it.second;
    }

    for (i = 0; i < n; i++) {
        temp += (v[i].first == v[i].second);
    }

    if (((n % 2 == 0) && (temp > 0)) || ((n % 2 == 1) && (temp > 1))) {
        cout << "-1\n";

        return;
    }

    if (temp == 1) {
        for (i = 0; i < n; i++) {
            if (v[i].first == v[i].second && (i != n / 2)) {
                swap(v[i], v[n / 2]);
                ops.push_back({i, n / 2});

                break;
            }
        }
    }

    mp.clear();

    for (i = 0; i < n; i++) {
        mp[{v[i].first, v[i].second}] = i;
    }

    for (i = 0; i < n; i++) {
        if (mp.find({v[i].second, v[i].first}) == mp.end()) {
            cout << "-1\n";

            return;
        }
    }

    for (i = 0; i < n; i++) {
        auto p = mp[{v[i].first, v[i].second}];
        auto q = mp[{v[i].second, v[i].first}];

        if (p + q == n - 1) {
            // do nothing
        }
        else {
            mp[{v[i].second, v[i].first}] = n - p - 1;
            mp[v[n - p - 1]] = q;

            swap(v[q], v[n - p - 1]);
            ops.push_back({q, n - p - 1});

        }
    }

    cout << ops.size() << "\n";

    for (auto &it : ops) {
        cout << it.first + 1 << " " << it.second + 1 << "\n";
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