#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, k, i, j, l = 0;

    cin >> n >> m >> k;

    vector <vector <int> > v(n, vector <int> (m));
    deque <int> dq;

    for (i = 1; i <= k; i++) {
        dq.push_back(i);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (l == dq.size() && i > 0 && v[i - 1][j] == dq.front()) {
                dq.pop_front();
                dq.push_back(v[i - 1][0]);
            }

            if (l == dq.size()) {
                l = 0;
            }

            v[i][j] = dq[l++];
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
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