#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, x, i;

    cin >> n >> k >> x;

    if (x == 1 && (k == 1)) {
        cout << "NO\n";

        return;
    }
    else if (x == 1 && (k == 2)) {
        if (n % 2 == 0) {
            cout << "YES\n";

            cout << n / 2 << "\n";

            for (i = 0; i < n / 2; i++) {
                cout << 2 << " ";
            }

            cout << "\n";
        }
        else {
            cout << "NO\n";
        }

        return;
    }
    else {
        cout << "YES\n";

        if (x == 1) {
            cout << n / 2 << "\n";

            if (n % 2 == 1) {
                for (i = 0; i < n / 2 - 1; i++) {
                    cout << 2 << " ";
                }

                cout << "3\n";
            }
            else {
                for (i = 0; i < n / 2; i++) {
                    cout << 2 << " ";
                }

                cout << "\n";
            }
        }
        else {
            cout << n << "\n";

            for (i = 0; i < n; i++) {
                cout << 1 << " ";
            }

            cout << "\n";
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