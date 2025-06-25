#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int ax, ay, bx, by, cx, cy, dx, dy;

    cin >> ax >> ay >> bx >> by >> cx >> cy;

    dx = ax + (cx - bx);
    dy = ay + (cy - by);

    cout << dx << " " << dy << " ";
    cout << abs(ax * by + bx * cy + cx * ay - bx * ay - cx * by - ax * cy) << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}