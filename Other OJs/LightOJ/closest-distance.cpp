#include <bits/stdc++.h>

using namespace std;

double y(double m, double Ay, double By)
{
    return Ay + m * (By - Ay);
}

double x(double m, double Ax, double Bx)
{
    return Ax + m * (Bx - Ax);
}

double d(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double dist(double m, double Ax, double Ay, double Bx, double By, double Cx, double Cy, double Dx, double Dy)
{
    double x1, y1, x2, y2;

    y1 = y(m, Ay, By);
    x1 = x(m, Ax, Bx);

    y2 = y(m, Cy, Dy);
    x2 = x(m, Cx, Dx);

    return d(x1, y1, x2, y2);
}

void solve()
{
    double Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
    double l = 0, r = 1.0, m1, m2;
    double d1, d2;
    int i;

    cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy >> Dx >> Dy;

    for (i = 0; i < 100; i++) {
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;

        d1 = dist(m1, Ax, Ay, Bx, By, Cx, Cy, Dx, Dy);
        d2 = dist(m2, Ax, Ay, Bx, By, Cx, Cy, Dx, Dy);

        if (d1 > d2) {
            l = m1;
        }
        else {
            r = m2;
        }
    }

    cout << dist(l, Ax, Ay, Bx, By, Cx, Cy, Dx, Dy) << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(9);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}