#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, b_min = 1e9, i, j;

    cin >> n >> m;

    vector <int> a(n), b(m), temp;

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (auto it : b) {
        b_min = min(b_min, it);
    }

    if (m == 1) {
        for (auto it : a) {
            cout << min(it, b_min) << " ";
        }

        cout << "\n";

        return;
    }

    for (i = 0; i < m; i++) {
        if (b[i] == b_min) {
            for (j = i; j < m; j++) {
                temp.push_back(b[j]);
            }

            for (j = 0; j < i; j++) {
                temp.push_back(b[j]);
            }

            break;
        }
    }

    b = temp;

    for (i = 0; i <= n - m; i++) {
        if (a[i] > b_min) {
            for (j = i; j <= n - m; j++) {
                a[j] = b_min;
            }

            for (i = n - m, j = 0; i < n; i++, j++) {
                a[i] = b[j];
            }
        }
    }

    for (i = n - m, j = 0; i < n; i++, j++) {
        if (a[i] < b[j]) {
            break;
        }
        else if (a[i] > b[j]) {
            for (i = n - m, j = 0; i < n; i++, j++) {
                a[i] = b[j];
            }

            break;
        }
    }

    for (auto it : a) {
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