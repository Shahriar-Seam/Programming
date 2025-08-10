#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, j, x, temp;

    cin >> n;

    vector <int> a(n), b(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    if (a[n - 1] != b[n - 1]) {
        cout << "NO\n";

        return;
    }

    for (i = 0; i < n; ) {
        if (a[i] != b[i]) {
            for (j = i + 1, x = 0; j < n; j++) {
                x ^= a[j];

                if ((a[i] ^ x) == b[i]) {
                    break;
                }
            }

            if (j == n) {
                cout << "NO\n";

                return;
            }
            else {
                temp = j;

                for (j = j - 1; j >= i; j--) {
                    a[j] ^= a[j + 1];

                    if (a[j] != b[j]) {
                        cout << "NO\n";

                        return;
                    }
                }

                i = temp;
            }
        }
        else {
            i++;
        }
    }

    cout << "YES\n";
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