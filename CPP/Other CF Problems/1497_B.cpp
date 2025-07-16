#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i, count = 0;
    map <int, int> mp;

    cin >> n >> m;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        mp[it % m]++;
    }

    for (i = 1; i < (m + 1) / 2; i++) {
        if (mp[i] || mp[m - i]) {
            count += max(1, abs(mp[i] - mp[m - i]));
        }
    }

    if (mp[0]) {
        count++;
    }

    if ((m % 2 == 0) && mp[m / 2]) {
        count++;
    }

    cout << count << "\n";
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