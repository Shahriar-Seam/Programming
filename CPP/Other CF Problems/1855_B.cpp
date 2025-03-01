#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i;

    cin >> n;

    for (i = 1; i < n; i++) {
        if (n % i != 0) {
            cout << i - 1 << "\n";

            return;
        }
    }

    cout << n << "\n";
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