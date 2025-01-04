#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i;
    map <int, int> mp;
    vector <pair <int, int> > vv;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        mp[it]++;
    }

    for (auto it : mp) {
        vv.push_back({it.second, it.first});
    }

    sort(vv.begin(), vv.end());

    for (i = 0; i < vv.size(); i++) {
        if (vv[i].first <= k) {
            k -= vv[i].first;
        }
        else {
            break;
        }
    }

    cout << max(vv.size() - i, 1ULL) << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}