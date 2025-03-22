#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, k, sum = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                cout << i << " " << j << " " << k << " ";
                cout << (v[i] & v[j]) * (v[j] | v[k]) << "\n";

                sum += (v[i] & v[j]) * (v[j] | v[k]);
            }
        }
    }

    cout << "Sum = " << sum << "\n";
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