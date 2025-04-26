#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i, j, val = -1;

    cin >> n >> m;

    vector <int> a(n), b(m);
    vector <pair <int, int> > indices(m);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (i = 0; i < m; i++) {
        indices[i] = {b[i], i};
    }

    for (i = 0, j = 0; i < n && j < m; j++) {
        while (i < n && a[i] < b[j]) {
            i++;
        }

        if (i == n) {
            break;
        }
        else {
            i++;
        }
    }

    if (j == m) {
        cout << 0 << "\n";

        return;
    }

    sort(indices.begin(), indices.end());

    for (auto it : indices) {
        for (i = 0, j = 0; i < n && j < m; j++) {
            if (j == it.second) {
                val = b[j];
            }
            else {
                while (i < n && a[i] < b[j]) {
                    i++;
                }

                if (i == n) {
                    break;
                }
                else {
                    i++;
                }
            }
        }

        if (j == m) {
            cout << val << "\n";

            return;
        }
        else {
            val = -1;
        }
    }

    cout << -1 << "\n";
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