#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, d = 0, i;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        mp[it]++;
    }

    cout << mp.size() * 2 - 1 << "\n";
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