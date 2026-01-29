#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, prv, f = 1;

    cin >> n;

    vector <pair <int, int> > v(n);

    for (auto &it : v) {
        cin >> it.first >> it.second;
    }

    reverse(v.begin(), v.end());

    prv = min(v[0].first, v[0].second);

    for (i = 1; i < n; i++) {
        if (v[i].first >= prv && v[i].second >= prv) {
            prv = min(v[i].first, v[i].second);
        }
        else if (v[i].first >= prv) {
            prv = v[i].first;
        }
        else if (v[i].second >= prv) {
            prv = v[i].second;
        }
        else {
            f = 0;
        }
    }

    cout << (f ? "YES" : "NO") << "\n";

    return 0;
}