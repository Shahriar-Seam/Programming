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

    sort(v.begin(), v.end(), greater <int> ());

    for (i = 2; i < n; i++) {
        if (v[i] != (v[i - 2] % v[i - 1])) {
            cout << -1 << "\n";

            return;
        }
    }

    cout << v[0] << " " << v[1] << "\n";
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