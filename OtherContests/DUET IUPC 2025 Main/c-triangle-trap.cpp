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

    T dot(P p) const {
        return x * p.x + y * p.y;
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

template <class P> bool onSegment(P s, P e, P p)
{
    return p.cross(s, e) == 0 && (s- p).dot(e- p) <= 0;
}

template <class P>
bool inPolygon(vector<P> p, P a, bool strict = true)
{
    int cnt = 0, n = p.size();

    for (int i = 0; i < n; i++) {
        P q = p[(i + 1) % n];
        if (onSegment(p[i], q, a))
            return !strict;
        cnt ^= ((a.y < p[i].y) - (a.y < q.y)) * a.cross(p[i], q) > 0;
    }
    return cnt;
}

void solve()
{
    int n, i, j, k, l;
    map <P, int> indices;

    cin >> n;

    vector <P> pts(n), hull;

    for (i = 0; i < n; i++) {
        cin >> pts[i];

        indices[pts[i]] = i + 1;
    }

    hull = convex_hull(pts);

    sort(hull.begin(), hull.end());

    for (i = 0; i < n; i++) {
        if (!binary_search(hull.begin(), hull.end(), pts[i])) {
            break;
        }
    }

    if (i == n) {
        cout << -1 << "\n";

        return;
    }

    j = 0;

    for (k = 1; k < hull.size(); k++) {
        for (l = k + 1; l < hull.size(); l++) {
            if (inPolygon({hull[j], hull[k], hull[l]}, pts[i])) {
                cout << i + 1 << " " << indices[hull[j]] << " " << indices[hull[k]] << " " << indices[hull[l]] << "\n";

                return;
            }
        }
    }
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