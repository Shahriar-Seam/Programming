#include <bits/stdc++.h>

using namespace std;

typedef struct {
    char type;
    double u, l, d, r;
    double x, y, rad;
} shape;

double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool is_inside(shape s, double x, double y)
{
    if (s.type == 'r') {
        return s.l < x && x < s.r && s.d < y && y < s.u;
    }
    else {
        return dist(s.x, s.y, x, y) < s.rad;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char type;
    int i, j = 1, f;
    vector <shape> shapes;

    while (true) {
        cin >> type;

        if (type == '*') {
            break;
        }

        if (type == 'r') {
            shape r;
            r.type = 'r';

            cin >> r.l >> r.u >> r.r >> r.d;

            shapes.push_back(r);
        }
        else {
            shape c;
            c.type = 'c';

            cin >> c.x >> c.y >> c.rad;

            shapes.push_back(c);
        }
    }

    while (true) {
        double x, y;

        cin >> x >> y;

        if (x == 9999.9 && y == 9999.9) {
            break;
        }

        f = 0;

        for (i = 0; i < shapes.size(); i++) {
            if (is_inside(shapes[i], x, y)) {
                cout << "Point " << j << " is contained in figure " << i + 1 << "\n";

                f = 1;
            }
        }

        if (!f) {
            cout << "Point " << j << " is not contained in any figure\n";
        }

        j++;
    }

    return 0;
}