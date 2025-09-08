#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, m, total = 0, cakes = 0, i, j, s;

    cin >> n >> m;

    vector <int> v(n), visited(n, 0);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (i = n - (m % n), j = 1; i < n && m; i++, j++, m--) {
        cakes += j * v[i];

        visited[i] = 1;
    }
    
    s = j;

    for (i = 0; i < n && m; i++, s++, m--) {
        cakes += min(s, n) * v[i];
    }

    for (i = 0; i < n; i++) {
        total += v[i] * n;
    }

    cakes += (m / n) * total;

    m %= n;

    for (i = 0; i < m; i++) {
        cakes += v[i] * n;
    }

    cout << cakes << "\n";


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