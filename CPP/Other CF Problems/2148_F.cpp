#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m = 0, i, j, k;
    int min_v, min_i, cnt = 0;

    cin >> n;

    vector <vector <int> > v(n, vector <int> ());
    set <int> s;
    vector <int> b;

    for (i = 0; i < n; i++) {
        cin >> k;

        v[i].assign(k, 0);

        m = max(m, k);

        s.insert(i);

        for (j = 0; j < k; j++) {
            cin >> v[i][j];
        }
    }

    for (i = 0; i < m; ) {
        min_v = 1e9;
        min_i = 0;
        cnt = 0;
        vector <int> temp;

        for (auto &it : s) {
            if (i < v[it].size() && v[it][i] < min_v) {
                min_v = v[it][i];

                min_i = it;
            }

            if (i >= v[it].size()) {
                temp.push_back(it);
            }
        }

        for (auto &it : temp) {
            s.erase(it);
        }

        for (auto &it : s) {
            if (v[it][i] == min_v) {
                cnt++;
            }
        }

        if (cnt == 1) {
            for (j = i; j < v[min_i].size(); j++) {
                b.push_back(v[min_i][j]);
            }

            s.erase(min_i);

            i = j;
        }
        else {
            b.push_back(v[min_i][i]);

            i++;
        }
    }

    for (auto &it : b) {
        cout << it << " ";
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