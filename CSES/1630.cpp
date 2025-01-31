#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, d = 0, rewards = 0;

    cin >> n;

    vector <pair <int, int> > v(n, pair <int, int> ());

    for (auto &it : v) {
        cin >> it.first >> it.second;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        d += v[i].first;

        rewards += v[i].second - d;
    }

    cout << rewards << "\n";

    return 0;
}