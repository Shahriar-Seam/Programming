#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, temp, a = 0, b = 0, c = 0, x, y, g;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    a = v[0];
    b = v[1];

    if ((2 * a - b) % (n - 1 + 2) != 0) {
        cout << "NO\n";

        return;
    }

    y = (2 * a - b) / (n - 1 + 2);
    x = a - (n - 1 + 1) * y;

    if (x < 0 || y < 0) {
        cout << "NO\n";

        return;
    }

    for (i = 3; i <= n; i++) {
        temp = v[i - 1];

        if (x * i + (n - i + 1) * y != temp) {
            cout << "NO\n";

            return;
        }
    }

    cout << "YES\n";
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