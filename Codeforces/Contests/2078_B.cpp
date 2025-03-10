#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i;

    cin >> n >> k;

    vector <int> a(n + 1, 0);

    if (k % 2 == 1) {
        for (i = 1; i <= n; i++) {
            a[i] = n;
        }

        a[n] = n - 1;
    }
    else {
        for (i = 1; i <= n; i++) {
            a[i] = n - 1;
        }

        a[n - 1] = n;
    }

    for (i = 1; i <= n; i++) {
        cout << a[i] << " ";
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