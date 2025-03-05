#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, c, i, j, k, cost = 0;
    string s;
    map <char, int> mp;
    vector <pair <int, char> > v;

    cin >> n >> c >> s;

    for (auto it : s) {
        mp[it]++;
    }

    for (auto it : mp) {
        v.push_back({it.second, it.first});
    }

    sort(v.begin(), v.end());

    s.clear();

    for (i = 0; i < v.size(); i++) {
        for (j = 0; j < v[i].first; j++) {
            s.push_back(v[i].second);
        }
    }

    for (i = 0, k = 1, cost = 0; i < v.size(); i++) {
        int temp = 0;

        for (j = 0; j < v[i].first; j++) {
            temp += k;
            k++;
        }

        if (temp >= c) {
            cost += c;

            k -= v[i].first;
        }
        else {
            cost += temp;
        }
    }

    cout << cost << "\n";
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