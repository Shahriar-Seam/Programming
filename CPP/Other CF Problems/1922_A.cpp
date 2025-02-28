#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, f = 0;
    string a, b, c, t;

    cin >> n >> a >> b >> c;

    for (i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            if (c[i] != a[i]) {
                f = 1;

                break;
            }
        }
        else {
            if (c[i] != a[i] && c[i] != b[i]) {
                f = 1;

                break;
            }

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