#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i, l, r;

    cin >> n >> k;

    vector <int> v(n, 0);

    if (n <= 60 && (1ll << (n - 1)) < k) {
        cout << -1 << "\n";

        return;
    }

    for (i = 1, l = 0, r = n - 1, k = k - 1; i <= n; ) {
        if (k & 1) {
            v[r--] = i++;
        }
        else {
            v[l++] = i++;
        }

        k /= 2;
    }

    for (auto &it : v) {
        cout << it << " ";
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