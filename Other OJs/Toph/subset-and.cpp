#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, x = (1 << 30) - 1;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        x &= it;
    }

    cout << (x < k ? "YES" : "NO") << "\n";
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