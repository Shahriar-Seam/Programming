#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        mp[it]++;
    }

    if (mp.size() > 2) {
        cout << "NO\n";

        return;
    }
    else if (mp.size() == 1) {
        cout << "YES\n";

        return;
    }

    for (auto it : mp) {
        if (it.second == n / 2) {
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