#include <bits/stdc++.h>

using namespace std;

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
    multiset <int> ms;

    cin >> n;

    vector <pair <pair <int, int>, int> > v(n);
    vector <bool> a(n, false), b(n, false);

    for (i = 0; i < n; i++) {
        cin >> v[i].first.first >> v[i].first.second;

        v[i].second = i;
    }

    sort(v.begin(), v.end(), compare);

    for (auto it : v) {
        ms.insert(it.first.second);
    }

    for (i = 0; i < n; i++) {
        ms.erase(ms.find(v[i].first.second));

        auto it = ms.lower_bound(v[i].first.second);

        if (it == ms.begin()) {
            if (*it == v[i].first.second) {
                a[v[i].second] = true;
            }
        }
        else {
            a[v[i].second] = true;
        }
    }

    for (auto it : v) {
        ms.insert(it.first.second);
    }

    for (i = n - 1; i >= 0; i--) {
        ms.erase(ms.find(v[i].first.second));

        auto it = ms.lower_bound(v[i].first.second);

        if (it != ms.end()) {
            b[v[i].second] = true;
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