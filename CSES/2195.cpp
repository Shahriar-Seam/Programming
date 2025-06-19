#include <bits/stdc++.h>

using namespace std;

#define int long long

template <class T> int sgn(T x)
{
    return (x > 0) - (x < 0);
}

template <class T> struct Point {
    typedef Point P;
    T x, y;

    explicit Point(T x = 0, T y = 0) : x(x), y(y) {}

    bool operator < (P p) const {
        return tie(x, y) < tie(p.x, p.y);
    }

    bool operator == (P p) const {
        return tie(x, y) == tie(p.x, p.y);
    }

    P operator - (P p) const {
        return P(x - p.x, y - p.y);
    }

    T cross(P p) const {
        return x * p.y - y * p.x;
    }

    T cross(P a, P b) const {
        return (a - *this).cross(b - *this);
    }

    friend istream& operator >> (istream &is, P &p) {
        return is >> p.x >> p.y;
    }

    friend ostream& operator << (ostream &os, P &p) {
        return os << p.x << " " << p.y;
    }
};

typedef Point <int> P;
vector <P> convex_hull(vector <P> pts)
{
    if (pts.size() <= 1) {
        return pts;
    }

    sort(pts.begin(), pts.end());

    vector <P> h(pts.size() + 5);

    int s = 0, t = 0;

    for (int it = 2; it--; s = --t, reverse(pts.begin(), pts.end())) {
        for (P p : pts) {
            while (t >= s + 2 && h[t - 2].cross(h[t - 1], p) < 0) {
                t--;
            }

            h[t++] = p;
        }
    }

    return {h.begin(), h.begin() + t - (t == 2 && h[0] == h[1])};
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector <P> pts(n), hull;

    for (auto &it : pts) {
        cin >> it;
    }

    hull = convex_hull(pts);

    cout << hull.size() << "\n";

    for (auto &it : hull) {
        cout << it << "\n";
    }

    return 0;
}