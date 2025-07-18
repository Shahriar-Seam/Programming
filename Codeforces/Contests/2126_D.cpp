#include <bits/stdc++.h>

using namespace std;

bool compare(const pair <int, pair <int, int> > &a, const pair <int, pair <int, int> > &b)
{
    if (a.first != b.first) {
        return a.first < b.first;
    }
    else {
        if (a.second.first != b.second.first) {
            return a.second.first < b.second.first;
        }
        else {
            return a.second.second > b.second.second;
        }
    }
}

int bin_search(vector <pair <int, pair <int, int> > > &v, int val)
{
    int l = 0, r = v.size() - 1, m, index = 0;

    while (l <= r) {
        m = (l + r) / 2;

        if (v[m].first >= val) {
            index = m;

            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    return index;
}

bool recurse(vector <pair <int, pair <int, int> > > &v, set <int> &pos, int val, int k, set <int> &impossible)
{
    if (val <= k) {
        pos.insert(val);

        return true;
    }

    if (impossible.find(val) != impossible.end()) {
        return false;
    }

    if (pos.upper_bound(val) == pos.end()) {
        int temp = bin_search(v, val);

        // cout << val << "\n";
        // cout << v[temp].second.first << "\n";

        if (val >= v[temp].second.first && val <= v[temp].second.second && recurse(v, pos, v[temp].second.first, k, impossible)) {
            pos.insert(val);

            return true;
        }
        else {
            impossible.insert(val);

            return false;
        }
    }
    else {
        return true;
    }
}

void solve()
{
    int n, k, i, f = 0;

    cin >> n >> k;

    vector <pair <int, pair <int, int> > > v(n);
    set <int> pos, impossible;

    for (i = 0; i < n; i++) {
        cin >> v[i].second.first >> v[i].second.second >> v[i].first;

        if (k >= v[i].second.first) {
            f = 1;
        }
    }

    if (!f) {
        cout << k << "\n";

        return;
    }

    sort(v.begin(), v.end());

    pos.insert(k);

    recurse(v, pos, v[n - 1].first, k, impossible);

    // cout << pos.size() << "\n";

    // for (auto &it : v) {
    //     cout << it.first << " " << it.second.first << " " << it.second.second << "\n";
    // }

    cout << *pos.rbegin() << "\n";
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