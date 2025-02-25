#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, max_val = 0, max_power = 0;

    cin >> n;

    vector <int> v(n), max_indices;

    for (auto &it : v) {
        cin >> it;
    }

    if (n == 2) {
        cout << abs(v[0] - v[1]) << "\n";

        return;
    }

    if (n == 3) {
        cout << max({v[0], v[2], v[1] - v[0] - v[2]}) << "\n";

        return;
    }

    for (i = 0; i < n; i++) {
        max_val = max(max_val, v[i]);
    }

    for (i = 0; i < n; i++) {
        if (v[i] == max_val) {
            max_indices.push_back(i);
        }
    }

    max_power = max(v[0], v[n - 1]);

    for (i = 0; i < max_indices.size(); i++) {
        if (max_indices[i] == 1) {
            max_power = max(max_power, abs(v[0] - v[1]));

            for (j = 2; j < n; j++) {
                if (j == n - 2) {
                    max_power = max(max_power, abs(v[j] - v[j + 1]));
                }
                else {
                    max_power = max(max_power, v[j]);
                }
            }
        }
        else if (max_indices[i] == n - 2) {
            max_power = max(max_power, abs(v[n - 1] - v[n - 2]));

            for (j = 0; j < n - 2; j++) {
                if (j == 1) {
                    max_power = max(max_power, abs(v[j] - v[j - 1]));
                }
                else {
                    max_power = max(max_power, v[j]);
                }
            }
        }
        else {
            max_power = max_val;
        }
    }

    cout << max_power << "\n";
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