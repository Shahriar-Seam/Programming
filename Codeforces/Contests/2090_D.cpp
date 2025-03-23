#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, f = 0;

    cin >> n;

    if (n % 2 == 1) {
        f = 1;

        n--;
    }

    for (i = n / 2, j = (n - 2) / 2; i <= n && j >= 0; i++, j--) {
        if (j == 0) {
            j = n;

            cout << i << " " << j << " ";

            break;
        }

        cout << i << " " << j << " ";
    }

    if (f) {
        cout << n + 1;
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