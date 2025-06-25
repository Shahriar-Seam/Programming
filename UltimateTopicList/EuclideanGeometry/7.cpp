#include <bits/stdc++.h>

using namespace std;

typedef struct {
    double u, l, d, r;
} rect;

bool is_inside(rect r, double x, double y)
{
    return r.l < x && x < r.r && r.d < y && y < r.u;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char op;
    int i, j = 1, f;
    vector <rect> rects;

    while (true) {
        cin >> op;

        if (op == '*') {
            break;
        }

        rect r;

        cin >> r.l >> r.u >> r.r >> r.d;

        rects.push_back(r);
    }

    while (true) {
        double x, y;

        cin >> x >> y;

        if (x == 9999.9 && y == 9999.9) {
            break;
        }

        f = 0;

        for (i = 0; i < rects.size(); i++) {
            if (is_inside(rects[i], x, y)) {
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