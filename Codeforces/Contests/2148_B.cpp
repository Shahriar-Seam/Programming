#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, x, y;

    cin >> n >> m >> x >> y;

    vector <int> a(n), b(m);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    cout << n + m << "\n";
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