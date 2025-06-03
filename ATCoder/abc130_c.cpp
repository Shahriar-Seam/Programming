#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(15);

    long long h, w, x, y;

    cin >> w >> h >> x >> y;

    cout << (h * w) / 2.0 << ((x * 2 == w && y * 2 == h) ? " 1" : " 0") << "\n";

    return 0;
}