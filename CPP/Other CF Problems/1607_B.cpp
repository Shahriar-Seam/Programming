#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int x, n, distance = 0;

    cin >> x >> n;

    if (n % 4 == 0) {
        distance = 0;
    }
    else if (n % 4 == 1) {
        distance = -n;
    }
    else if (n % 4 == 2) {
        distance = 1;
    }
    else if (n % 4 == 3) {
        distance = n + 1;
    }

    if (x % 2 == 0) {
        cout << x + distance << "\n";
    }
    else {
        cout << x - distance << "\n";
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