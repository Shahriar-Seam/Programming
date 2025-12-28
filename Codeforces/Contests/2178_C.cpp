#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, x = -1e18, ab = 0, inv = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        inv -= it;
    }

    for (i = 0; i < n; i++) {
        inv += v[i];

        x = max(x, ab + inv);

        if (i == 0) {
            ab += v[i];
        }
        else {
            ab += abs(v[i]);
        }
    }

    cout << x << "\n";
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