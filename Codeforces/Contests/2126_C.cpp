#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, k, k_val, water = 1, i = 0, f = 1;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    k_val = v[k - 1];

    sort(v.begin(), v.end());

    i = upper_bound(v.begin(), v.end(), k_val) - v.begin() - 1;

    for (i = i + 1; i < n; i++) {
        if (v[i] - v[i - 1] <= v[i - 1] - water + 1) {
            water += v[i] - v[i - 1];
        }
        else {
            f = 0;

            break;
        }
    }

    cout << (f ? "YES" : "NO") << "\n";
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