#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i;
    string a, b, c;

    cin >> n >> a >> m >> b >> c;

    for (i = 0; i < m; i++) {
        if (c[i] == 'D') {
            a += b[i];
        }
        else {
            a.insert(a.begin(), b[i]);
        }
    }

    cout << a << "\n";
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