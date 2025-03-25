#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        mp[v[i]]++;

        if (mp[0] >= 3 && mp[1] >= 1 && mp[2] >= 2 && mp[3] >= 1 && mp[5] >= 1) {
            cout << i + 1 << "\n";

            return;
        }
    }

    cout << 0 << "\n";
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