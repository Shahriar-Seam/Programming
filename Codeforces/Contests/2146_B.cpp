#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i, j, l, count = 0;

    cin >> n >> m;

    vector <vector <int> > v(n), s(m + 1);
    vector <bool> taken(n, false), must(n, false);

    for (i = 0; i < n; i++) {
        cin >> l;

        v[i].assign(l, 0);

        for (j = 0; j < l; j++) {
            cin >> v[i][j];

            s[v[i][j]].push_back(i);
        }
    }

    for (i = 1; i <= m; i++) {
        sort(s[i].begin(), s[i].end());
    }

    for (i = 1; i <= m; i++) {
        if (s[i].empty()) {
            cout << "NO\n";

            return;
        }
        else if (s[i].size() == 1) {
            taken[s[i][0]] = 1;
        }
    }

    for (i = 0; i < n; i++) {
        if (!taken[i]) {
            count++;
        }
    }

    // for (i = 1; i <= m; i++) {
    //     cout << i << " : ";

    //     for (auto &it : s[i]) {
    //         cout << it << " ";
    //     }

    //     cout << "\n";
    // }

    cout << (count >= 2 ? "YES" : "NO") << "\n";
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