#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, s, max_satisfaction = 0;

    cin >> n;

    vector <pair <int, int> > v(n);
    map <int, vector <int> > mp;

    for (auto &it : v) {
        cin >> it.second >> it.first;
    }

    sort(v.begin(), v.end(), greater <pair <int, int> > ());

    s = v[0].first;

    for (i = 1; i < n; i++) {
        if (v[i].second != v[0].second) {
            max_satisfaction = max(max_satisfaction, s + v[i].first);
        }
        else {
            max_satisfaction = max(max_satisfaction, s + v[i].first / 2);
        }
    }

    cout << max_satisfaction << "\n";

    return 0;
}