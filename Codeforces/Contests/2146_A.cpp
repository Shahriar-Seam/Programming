#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, count = 0, i, cnt;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        mp[it]++;
    }

    for (i = 1; i <= 100; i++) {
        cnt = 0;

        for (auto &it : mp) {
            if (it.second >= i) {
                cnt += i;
            }
        }

        count = max(count, cnt);
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