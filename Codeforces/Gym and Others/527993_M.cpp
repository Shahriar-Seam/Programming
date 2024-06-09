#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int sx, sy, tx, ty, k;
    int distx, disty, add = 0;

    cin >> sx >> sy >> tx >> ty >> k;

    distx = abs(sx - tx);
    disty = abs(sy - ty);

    if (disty < (distx / k)) {
        add += (distx / k) - disty;
    }

    if (distx < (disty / k)) {
        add += (disty / k) - distx;
    }

    cout << distx + disty + add << "\n";
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