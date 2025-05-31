#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    if (min(a, c) < min(b, d)) {
        cout << "Flower\n";
    }
    else if ((min(a, c) > min(b, d))) {
        cout << "Gellyfish\n";
    }
    else {
        cout << "Gellyfish\n";
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