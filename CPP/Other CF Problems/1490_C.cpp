#include <bits/stdc++.h>

using namespace std;

#define int long long

bool is_cube(int n)
{
    int l = 1, r = 1e4, m, temp;

    while (l <= r) {
        m = (l + r) / 2;

        if (m * m * m <= n) {
            temp = m * m * m;

            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    return temp == n;
}

void solve()
{
    int n, i;

    cin >> n;

    for (i = 1; i <= 1e4; i++) {
        if (is_cube(n - i * i * i)) {
            cout << "YES\n";

            return;
        }
    }

    cout << "NO\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}