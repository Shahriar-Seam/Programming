#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, g = 0;

    cin >> n;

    vector <int> v(n), distances(n, 0);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        distances[i] = abs(v[i] - i - 1);
    }

    for (auto it : distances) {
        g = gcd(g, it);
    }

    cout << g << "\n";
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