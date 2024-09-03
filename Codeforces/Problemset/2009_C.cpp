#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x, y, k, x_s = 0, y_s = 0, i;

    cin >> x >> y >> k;

    if (y >= x) {
        y_s = 2 * ceil(y * 1.0 / k);
    }
    else {
        x_s = 2 * ceil(x * 1.0 / k) - 1;
    }

    cout << x_s + y_s << "\n";
}

int main()
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