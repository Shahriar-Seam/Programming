#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, k, i, sum = 0;

    cin >> n >> k;

    vector <int> v(n), pref(n + 1);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + v[i];
    }

    for (i = 0; i <= k; i++) {
        sum = max(sum, pref[n - k + i] - pref[2 * i]);
    }

    cout << sum << "\n";
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