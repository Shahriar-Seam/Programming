#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, k, i, gold = 0;
    multiset <int> ms;

    cin >> n >> k;

    vector <pair <int, int> > v(n), temp;
    vector <int> golds(n + 1, 0);

    for (i = 0; i < n; i++) {
        cin >> v[i].first;
    }

    for (i = 0; i < n; i++) {
        cin >> v[i].second;
    }

    temp = v;

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        if (ms.size() < k) {
            ms.insert(v[i].second);
            gold += v[i].second;
        }
        else {
            ms.insert(v[i].second);

            auto it = ms.begin();

            gold = gold + v[i].second - *it;

            ms.erase(it);
        }

        golds[v[i].first] = gold;
    }

    for (auto it : temp) {
        cout << golds[it.first - 1] << " ";
    }

    cout << "\n";
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