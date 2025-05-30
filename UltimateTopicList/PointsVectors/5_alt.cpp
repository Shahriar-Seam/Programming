#include <bits/stdc++.h>

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(10);

    freopen("angle1.in", "r", stdin);
    freopen("angle1.out", "w", stdout);

    complex <double> p;
    double x, y;

    cin >> x >> y;

    p = {x, y};

    if (arg(p) < 0) {
        cout << 2 * acos(-1) + arg(p) << "\n";
    }
    else {
        cout << arg(p) << "\n";
    }

    return 0;
}