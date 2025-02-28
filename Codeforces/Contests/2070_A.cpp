#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i;

    cin >> n;

    if (n % 15 == 0) {
        cout << (n / 15) * 3 + 1 << "\n";
    }
    else if (n % 15 == 1) {
        cout << (n / 15) * 3 + 2 << "\n";
    }
    else {
        cout << (n / 15) * 3 + 3 << "\n";
    }

    // cout << (n / 15 + 1) * 3 << "\n";
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