#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, sum = 0, i;

    cin >> n;

    vector <int> v(n), pref_max(n + 1, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        pref_max[i + 1] = max(pref_max[i], v[i]);
    }

    for (i = n - 1; i >= 0; i--) {
        if (i < n - 1) {
            sum += v[i + 1];
        }

        cout << sum + pref_max[i + 1] << " ";
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