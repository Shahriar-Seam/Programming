#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j = -1;
    map <int, int, greater <> > mp;

    cin >> n;

    vector <int> v(n), temp;

    for (i = 0; i < n; i++) {
        cin >> v[i];

        mp[v[i]] = i;
    }

    for (i = n; i > 0; i--) {
        if (v[n - i] == i) {
            temp.push_back(i);

            mp.erase(i);
        }
        else {
            break;
        }
    }

    j = n - i - 1;

    if (!mp.empty()) {
        auto p = *mp.begin();

        for (i = p.second; i > j; i--) {
            temp.push_back(v[i]);

            mp.erase(v[i]);
        }
    }

    for (i = 0; i < n; i++) {
        if (mp.find(v[i]) != mp.end()) {
            temp.push_back(v[i]);
        }
    }

    for (auto &it : temp) {
        cout << it << " ";
    }

    cout << "\n";
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