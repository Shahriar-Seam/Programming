#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, x = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (auto it : v) {
        x ^= it;
    }

    cout << ((n & 1) ? x : (x == 0) ? x : -1) << "\n";
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