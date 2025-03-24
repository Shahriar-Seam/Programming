#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree <pair <int, int>, null_type, less <pair <int, int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int inf = 1e9 + 5;

bool compare(pair <pair <int, int>, int> a, pair <pair <int, int>, int> b)
{
    if (a.first.first < b.first.first) {
        return true;
    }
    else if (a.first.first > b.first.first) {
        return false;
    }
    else {
        return a.first.second > b.first.second;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    ordered_set ms;

    cin >> n;

    vector <pair <pair <int, int>, int> > v(n);
    vector <int> a(n, 0), b(n, 0);

    for (i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second;

        v[i].second = i;
    }

    sort(v.begin(), v.end(), compare);

    for (i = 0; i < n; i++) {
        ms.insert({v[i].first.second, i});
    }

    for (i = 0; i < n; i++) {
        ms.erase(ms.find({v[i].first.second, i}));

        auto it = ms.order_of_key({v[i].first.second, inf});

        if (it > 0) {
            a[v[i].second] += it;
        }
    }

    for (i = 0; i < n; i++) {
        ms.insert({v[i].first.second, i});
    }

    for (i = n - 1; i >= 0; i--) {
        ms.erase(ms.find({v[i].first.second, i}));

        auto it = ms.order_of_key({v[i].first.second, -inf});

        if (it != ms.size()) {
            b[v[i].second] += ms.size() - it;
        }
    }

    for (auto it : a) {
        cout << it << " ";
    }

    cout << "\n";

    for (auto it : b) {
        cout << it << " ";
    }

    cout << "\n";

    return 0;
}