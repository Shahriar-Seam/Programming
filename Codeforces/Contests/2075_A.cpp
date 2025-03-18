#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;

    cin >> n >> k;

    if (n % 2 == 1) {
        if (k % 2 == 1) {
            cout << 1 + (n - 2) / (k - 1) << "\n";
        }
        else {
            cout << 1 + (n - 1) / k << "\n";
        }
    }
    else {
        if (k % 2 == 1) {
            cout << (n + k - 2) / (k - 1) << "\n";
        }
        else {
            cout << (n + k - 1) / k << "\n";
        }
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