#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, count = 0, i;
    map <int, int> mp;

    cin >> n;

    vector <int> v(n);
    vector <pair <int, int> > cnt;

    for (auto &it : v) {
        cin >> it;

        mp[it]++;
    }

    for (auto &it : mp) {
        cnt.push_back({it.first, it.second});
    }

    count = cnt[0].second;

    for (i = 1; i < cnt.size(); i++) {
        if ((cnt[i].first == cnt[i - 1].first + 1) && (cnt[i].second > cnt[i - 1].second)) {
            count += cnt[i].second - cnt[i - 1].second;
        }
        else if (cnt[i].first > cnt[i - 1].first + 1) {
            count += cnt[i].second;
        }
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