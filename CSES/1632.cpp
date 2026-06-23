#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, i, count = 0, inf = 1e9 + 5;
    set <pair <int, int> > s;

    cin >> n >> k;

    vector <pair <int, int> > v(n);

    for (i = 1; i <= k; i++) {
        s.insert({0, i});
    }

    for (auto &it : v) {
        cin >> it.first >> it.second;
    }

    sort(v.begin(), v.end(), [&] (pair <int, int> &a, pair <int, int> &b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        else {
            return a.second < b.second;
        }
    });

    for (auto &it : v) {
        auto jt = s.upper_bound({it.first, inf});

        if (jt == s.begin()) {
            continue;
        }

        auto top = *--jt;

        if (top.first <= it.first) {
            top.first = it.second;

            s.erase(jt);

            s.insert(top);

            count++;
        }
    }

    cout << count << "\n";

    return 0;
}