#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, max_val = 0, i;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    if (n == 1) {
        cout << 0 << "\n";

        return;
    }

    for (i = 1; i < n; i++) {
        max_val = max(max_val, v[i - 1] - v[i]);
    }

    n--;

    cout << max({max_val, v[n] - v[0], *max_element(v.begin() + 1, v.end()) - v[0], v[n] - *min_element(v.begin(), v.begin() + n)}) << "\n";
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