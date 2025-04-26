#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, i, count = 0, x;
    int mi = 2e9, ma = -1;

    cin >> n >> k;

    vector <int> a(n), b(n);

    for (auto &it : a) {
        cin >> it;

        if (it >= 0) {
            mi = min(mi, it);
            ma = max(ma, it);
        }
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (int i = 0; i < n; i++) {
        if (b[i] >= 0) {
            count = 1;
        }
    }

    if (count) {
        for (i = 0; i < n; i++) {
            if (b[i] >= 0) {
                x = a[i] + b[i];

                break;
            }
        }

        for (i = 0; i < n; i++) {
            if (b[i] < 0 && (x - a[i] > k || x - a[i] < 0)) {
                cout << 0 << "\n";

                return;
            }
            else if (b[i] >= 0 && a[i] + b[i] != x) {
                cout << 0 << "\n";

                return;
            }
        }

        cout << 1 << "\n";
    }
    else {
        cout << mi + k - ma + 1 << "\n";
    }
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