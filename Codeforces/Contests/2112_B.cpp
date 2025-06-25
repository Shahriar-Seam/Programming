#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 1; i < n; i++) {
        if (abs(v[i] - v[i - 1]) <= 1) {
            cout << 0 << "\n";
 
            return;
        }
    }

    for (i = 1; i < n - 1; i++) {
        if (((v[i - 1] >= min(v[i], v[i + 1]) - 1) && (v[i - 1] <= max(v[i], v[i + 1]) + 1)) || (v[i + 1] >= min(v[i], v[i - 1]) - 1) && (v[i + 1] <= max(v[i], v[i - 1]) + 1)) {
            cout << 1 << "\n";

            return;
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