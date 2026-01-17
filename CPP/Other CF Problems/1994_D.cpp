#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, x, i, temp;

    cin >> n;

    list <pair <int, int> > a;
    vector <pair <int, int> > e;

    for (i = 0; i < n; i++) {
        cin >> temp;

        a.push_back({temp, i + 1});
    }

    for (x = n - 1; x > 0; x--) {
        vector <int> pos(n, 0);

        for (auto it = a.begin(); it != a.end(); it++) {
            if (!pos[it->first % x]) {
                pos[it->first % x] = it->second;
            }
            else {
                e.push_back({it->second, pos[it->first % x]});

                a.erase(it);

                break;
            }
        }
    }

    cout << "YES\n";

    reverse(e.begin(), e.end());

    for (auto &it : e) {
        cout << it.first << " " << it.second << "\n";
    }
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