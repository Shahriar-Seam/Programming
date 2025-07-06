#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, l, r, k;

    cin >> n >> l >> r >> k;

    if (n & 1) {
        cout << l << "\n";

        return;
    }

    if (n == 2) {
        if ((l & l) == (l ^ l)) {
            cout << l << "\n";
        }
        else {
            cout << "-1\n";
        }

        return;
    }

    if ((1LL << (64 - __builtin_clzll(l))) <= r) {
        if (k >= n - 1) {
            cout << (1LL << (64 - __builtin_clzll(l))) << "\n";
        }
        else {
            cout << l << "\n";
        }
    }
    else {
        cout << -1 << "\n";
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