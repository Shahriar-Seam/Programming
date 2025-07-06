#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int a, b, x, y;

    cin >> a >> b >> x >> y;

    if (a > b) {
        if ((a & 1) && a == b + 1) {
            cout << y << "\n";
        }
        else {
            cout << "-1\n";
        }

        return;
    }

    if (x <= y) {
        cout << (b - a) * x << "\n";
    }
    else {
        int cost = 0;

        if (a & 1) {
            a++;

            cost += x;
        }

        if (b & 1) {
            b--;

            cost += y;
        }

        cost += ((b - a) / 2) * (x + y);

        cout << cost << "\n";
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