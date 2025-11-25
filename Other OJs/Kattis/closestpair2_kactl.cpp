#include <bits/stdc++.h>

using namespace std;

const double inf = 1e100;
const double eps = 1e-9;

struct pt {
    double x, y;

    pt(double x = 0, double y = 0) : x(x), y(y) {}

    bool operator < (pt p) const {
        if (x == p.x) {
            return y < p.y;
        }
        else {
            return x < p.x;
        }
    }

    pt operator + (pt p) const {
        return pt(x + p.x, y + p.y);
    }

    pt operator - (pt p) const {
        return pt(x - p.x, y - p.y);
    }

    bool operator == (pt p) const {
        return abs(x - p.x) <= eps && abs(y - p.y) <= eps;
    }

    double sq() const {
        return x * x + y * y;
    }
};

istream& operator >> (istream& is, pt &p) {
    return is >> p.x >> p.y;
}

ostream& operator << (ostream& os, pt p) {
    return os << p.x << " " << p.y;
}

pair <pt, pt> closest_pair(vector <pt> v)
{
    set <pt> S;

    sort(v.begin(), v.end(), [] (pt a, pt b) {
        return a.y < b.y;
    });

    pair <double, pair <pt, pt> > ret{inf, {pt(), pt()}};

    int j = 0;

    for (pt p : v) {
        pt d{1 + sqrt(ret.first), 0};

        while (v[j].y <= p.y - d.x) {
            S.erase(v[j++]);
        }

        auto lo = S.lower_bound(p - d), hi = S.upper_bound(p + d);

        for ( ; lo != hi; lo++) {
            ret = min(ret, {(*lo - p).sq(), {*lo, p}});
        }

        S.insert(p);
    }

    return ret.second;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(2);

    int n;

    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        vector <pt> v(n);

        for (auto &it : v) {
            cin >> it;
        }

        pair <pt, pt> p = closest_pair(v);

        cout << p.first << " " << p.second << "\n";
    }

    return 0;
}