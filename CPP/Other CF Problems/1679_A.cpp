#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, a = 1e9, b, i;

    cin >> n;

    if (n == 2 || (n % 2 == 1)) {
        cout << -1 << "\n";

        return;
    }
    
    for (i = 0; i <= 3; i++) {
        if ((n - i * 4) % 6 == 0) {
            a = (n - i * 4) / 6 + i;

            break;
        }
    }

    for (i = 0; i <= 2; i++) {
        if ((n - i * 6) % 4 == 0) {
            b = (n - i * 6) / 4 + i;

            break;
        }
    }

    cout << a << " " << b << "\n";
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