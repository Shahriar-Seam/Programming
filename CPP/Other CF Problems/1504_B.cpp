#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, o = 0, z = 0, f = 0;
    string a, b;

    cin >> n >> a >> b;

    for (i = 0; i < n; i++) {
        o += (a[i] == '1');
        z += (a[i] == '0');
    }

    for (i = n - 1; i >= 0; i--) {
        if ((a[i] + f) % 2 != (b[i] % 2)) {
            if (o == z) {
                f++;
                swap(o, z);               
            }
            else {
                cout << "NO\n";

                return;
            }
        }

        if ((a[i] + f) & 1) {
            o--;
        }
        else {
            z--;
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