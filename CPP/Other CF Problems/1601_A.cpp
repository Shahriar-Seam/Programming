#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, a, k, f;
    int count[32] = {};

    cin >> n;

    for (j = 0; j < n; j++) {
        cin >> a;

        for (i = 0; i < 31; i++) {
            if (a & (1 << i)) {
                count[i]++;
            }
        }
    }

    for (k = 1; k <= n; k++) {
        f = 1;

        for (i = 0; i < 31; i++) {
            if (count[i] % k != 0) {
                f = 0;

                break;
            }
        }

        if (f) {
            cout << k << " ";
        }
    }

    cout << "\n";
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