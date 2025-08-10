#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    for (i = 1; i < n; i++) {
        if (i & 1) {
            cout << -1 << " ";
        }
        else {
            cout << 3 << " ";
        }
    }

    if (n % 2 == 0) { 
        cout << 2 << "\n";
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