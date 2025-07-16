#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, x, y, count = 0;
    map <pair <int, int>, int> mp;

    cin >> n >> x >> y;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        mp[{(it % x), (it % y)}]++;
    }

    for (auto &it : mp) {
        if (it.first.first == 0) {
            count += it.second * (it.second - 1);
        }
        else if ((x % 2 == 0) && it.first.first == x / 2) {
            count += it.second * (it.second - 1);
        }
        else {
            count += (it.second * mp[{x - it.first.first, it.first.second}]);
        }
    }

    cout << count / 2 << "\n";
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