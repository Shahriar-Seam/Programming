#include <bits/stdc++.h>

using namespace std;

int one(int x, int n, int m)
{
    while ((n || m) && (x > 0)) {
        if (m > 0) {
            x = (x + 1) / 2;

            m--;
        }
        else {
            x /= 2;

            n--;
        }

        if (x == 1 && n > 0) {
            x = 0;

            break;
        }
        else if (x == 1 && n == 0) {
            break;
        }
    }

    return x;
}

int two(int x, int n, int m)
{
    while ((n || m) && (x > 0)) {
        if (n > 0) {
            x /= 2;

            n--;
        }
        else {
            x = (x + 1) / 2;

            m--;
        }

        if (x == 1 && n == 0) {
            break;
        }
    }

    return x;
}

void solve()
{
    int x, n, m;

    cin >> x >> n >> m;

    cout << one(x, n, m) << " " << two(x, n, m) << "\n";
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