#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = n - 2; i >= max(0, n - 5000); i--) {
        for (j = i + 1; j < n; j++) {
            if ((v[j] % v[i]) % 2 == 0) {
                cout << v[i] << " " << v[j] << "\n";

                return;
            }
        }
    }

    cout << "-1\n";
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