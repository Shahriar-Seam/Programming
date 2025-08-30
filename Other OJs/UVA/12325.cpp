#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, s1, v1, s2, v2, i, x, max_val = 0;

    cin >> n >> s1 >> v1 >> s2 >> v2;

    for (i = 0; i * i <= n; i++) {
        x = n - s1 * i;

        if (x < 0) {
            break;
        }

        max_val = max(max_val, i * v1 + (x / s2) * v2);
    }

    for (i = 0; i * i <= n; i++) {
        x = n - s2 * i;

        if (x < 0) {
            break;
        }

        max_val = max(max_val, i * v2 + (x / s1) * v1);
    }

    cout << max_val << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";

        solve();
    }

    return 0;
}