#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, x, y, count = 0, i;
    map <pair <int, int>, int> mp;

    cin >> n >> x >> y;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        count += mp[{(x - v[i] % x) % x, v[i] % y}];

        mp[{v[i] % x, v[i] % y}]++;
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