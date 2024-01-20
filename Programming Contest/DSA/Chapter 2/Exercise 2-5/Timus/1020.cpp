#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    double r, x, y, x1, x2, y1, y2, d = 0, pi = acos(-1);

    cin >> n >> r;
    cin >> x1 >> y1;
    
    x = x1;
    y = y1;

    for (i = 1; i < n; i++) {
        cin >> x2 >> y2;

        d += sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

        x1 = x2;
        y1 = y2;
    }
    
    d += sqrt((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y));

    cout << d + 2 * pi * r;

    return 0;
}