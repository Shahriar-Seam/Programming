#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n), pref(n + 1, 0);

    for (i = 0; i < n; i++) {
        cin >> v[i];

        if (i & 1) {
            v[i] *= -1;
        }
    }

    mp[0]++;

    for (i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + v[i];

        mp[pref[i + 1]]++;
    }

    for (auto &it : mp) {
        if (it.second > 1) {
            cout << "YES\n";

            return;
        }
    }

    cout << "NO\n";
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