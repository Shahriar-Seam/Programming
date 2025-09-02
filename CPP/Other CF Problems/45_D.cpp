#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    set <int> s;

    cin >> n;

    vector <pair <int, pair <int, int> > > v(n);
    vector <int> days(n);

    for (i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second.first;

        v[i].second.second = i;
    }

    // sort(v.begin(), v.end(), [&] (pair <int, pair <int, int> > &a, pair <int, pair <int, int> > &b) {
    //     if (a.second.first == b.second.first) {
    //         return a.first > b.first;
    //     }
    //     else {
    //         return a.second.first < b.second.first;
    //     }
    // });

    sort(v.begin(), v.end());

    for (auto &it : v) {
        cout << it.first << " " << it.second.first << "\n";
    }

    cout << "\n";

    for (auto &it : v) {
        while (s.find(it.second.first) != s.end()) {
            it.second.first--;
        }

        s.insert(it.second.first);

        days[it.second.second] = it.second.first;
    }

    for (auto &it : v) {
        cout << it.first << " " << it.second.first << "\n";
    }

    for (auto &it : days) {
        cout << it << " ";
    }

    cout << "\n";

    return 0;
}