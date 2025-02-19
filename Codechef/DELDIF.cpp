#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, count = 0;
    map <int, int> mp;
    set <int> s;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        mp[it]++;
    }

    for (auto it : mp) {
        if (it.second % 2 != 0) {
            s.insert(it.first);
        }

        if (it.second > 1) {
            s.insert(0);
        }
    }

    cout << s.size() << "\n";
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