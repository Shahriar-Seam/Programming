#include <bits/stdc++.h>

using namespace std;

struct pt {
    double x, y;

    bool operator < (pt p) const {
        if (x == p.x) {
            return y < p.y;
        }
        else {
            return x < p.x;
        }
    }
};

istream& operator >> (istream& is, pt &p) {
    return is >> p.x >> p.y;
}

ostream& operator << (ostream& os, pt p) {
    return os << p.x << " " << p.y;
}

pair <pt, pt> closest_pair(vector <pt> points)
{
    vector <pt> l(points.begin(), points.begin() + points.size() / 2), r(points.begin() + points.size() / 2, points.end());

    

    return {{0, 0}, {0, 0}};
}

void solve()
{
    int n;

    cin >> n;

    vector <pt> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    smallest_distance(v);

    cout << "bello\n";
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