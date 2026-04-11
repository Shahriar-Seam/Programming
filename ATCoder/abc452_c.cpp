#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, f;
    int mp[11][26][11] = {};

    cin >> n;

    vector <pair <int, int> > ab(n);

    for (auto &it : ab) {
        cin >> it.first >> it.second;
    }

    cin >> m;

    vector <string> s(m);

    for (auto &it : s) {
        cin >> it;

        for (i = 0; i < it.size(); i++) {
            mp[it.size()][it[i] - 'a'][i] = 1;
        }
    }

    for (auto &it : s) {
        if (it.size() != n) {
            cout << "No\n";
        }
        else {
            f = 1;

            for (i = 0; i < n; i++) {
                if (!mp[ab[i].first][it[i] - 'a'][ab[i].second - 1]) {
                    f = 0;

                    break;
                }
            }

            cout << (f ? "Yes" : "No") << "\n";
        }
    }

    return 0;
}