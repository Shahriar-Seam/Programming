#include <bits/stdc++.h>

using namespace std;

typedef double T;
const double PI = acos(-1);

struct pt {
    T x, y;
    pt operator+(pt p) { return {x + p.x, y + p.y}; }
    pt operator-(pt p) { return {x - p.x, y - p.y}; }
    pt operator*(T d) { return {x * d, y * d}; }
    pt operator/(T d) { return {x / d, y / d}; }
    int pos() const { if (y < 0) return -1; if (y == 0 && x >= 0) return 0; return 1; }
    bool operator<(pt r) const {
        if (pos() != r.pos()) return pos() < r.pos();
        return x * r.y - y * r.x > 0;
    }
};

bool operator==(pt a, pt b) { return a.x == b.x && a.y == b.y; }
bool operator!=(pt a, pt b) { return !(a == b); }
T sq(pt p) { return p.x * p.x + p.y * p.y; }
double abs(pt p) { return sqrt(sq(p)); }
istream& operator>>(istream& is, pt &p) { return is >> p.x >> p.y; }
ostream& operator<<(ostream& os, pt p) { return os << p.x << " " << p.y; }
template<typename T> int sgn(T x) { return (T(0) < x) - (x < T(0)); }
pt translate(pt v, pt p) { return p + v; }
pt scale(pt c, double f, pt p) { return c + (p - c) * f; }
pt rot(pt p, double a) { return {p.x * cos(a) - p.y * sin(a), p.x * sin(a) + p.y * cos(a)}; }
pt perp(pt p) { return {-p.y, p.x}; }
T dot(pt v, pt w) { return v.x * w.x + v.y * w.y; }
bool is_perp(pt v, pt w) { return dot(v, w) == 0; }
double angle(pt v, pt w) { return acos(max(-1.0, min(1.0, dot(v, w) / abs(v) / abs(w)))); }
T cross(pt v, pt w) { return v.x * w.y - v.y * w.x; }
pt linear_transform(pt p, pt q, pt r, pt fp, pt fq) {
    pt pq = q - p, num{cross(pq, fq - fp), dot(pq, fq - fp)};
    return fp + pt{cross(r - p, num), dot(r - p, num)} / sq(pq);
}
T orient(pt a, pt b, pt c) { return cross(b - a, c - a); }
bool is_in_angle(pt a, pt b, pt c, pt p) {
    assert(orient(a, b, c));
    if (orient(a, b, c) < 0) swap(b, c);
    return orient(a, b, p) >= 0 && orient(a, c, p) <= 0;
}
double oriented_angle(pt a, pt b, pt c) {
    return orient(a, b, c) >= 0 ? angle(b - a, c - a) : 2 * PI - angle(b - a, c - a);
}
bool is_convex(vector<pt> p) {
    bool pos = 0, neg = 0;
    for (int i = 0, n = p.size(); i < n; i++) {
        T o = orient(p[i], p[(i + 1) % n], p[(i + 2) % n]);
        if (o > 0) pos = 1;
        if (o < 0) neg = 1;
    }
    return !(pos && neg);
}

struct line {
    pt v; T c;
    line() {}
    line(pt v, T c): v(v), c(c) {}
    line(T a, T b, T c): v({b, -a}), c(c) {}
    line(pt p, pt q): v(q - p), c(cross(v, p)) {}
    T side(pt p) { return cross(v, p) - c; }
    double dist(pt p) { return abs(side(p)) / abs(v); }
    double sq_dist(pt p) { return side(p) * side(p) / (double)sq(v); }
    line perp_through(pt p) { return {p, p + perp(v)}; }
    bool cmp_proj(pt p, pt q) { return dot(v, p) < dot(v, q); }
    line translate(pt t) { return {v, c + cross(v, t)}; }
    line shift_left(double d) { return {v, c + d * abs(v)}; }
    bool inter(line l1, line l2, pt &out) {
        T d = cross(l1.v, l2.v);
        if (d == 0) return 0;
        out = (l2.v * l1.c - l1.v * l2.c) / d;
        return 1;
    }
    pt proj(pt p) { return p - perp(v) * side(p) / sq(v); }
    pt refl(pt p) { return p - perp(v) * 2 * side(p) / sq(v); }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(8);

    int n, i;
    pt p;
    line l;
    T r1 = 1e18, r2 = 0;

    cin >> n >> p;

    vector <pt> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    v.push_back(v[0]);

    for (i = 1; i <= n; i++) {
        l = {v[i - 1], v[i]};

        T temp_r = l.dist(p);
        pt temp_p = l.proj(p);

        if (sgn(line({p, v[i - 1]}).side(temp_p)) != sgn(line({p, v[i]}).side(temp_p))) {
            r1 = min(r1, temp_r);
        }
        else {
            r1 = min({r1, abs(p - v[i - 1]), abs(p - v[i])});
        }

        r2 = max(r2, abs(v[i] - p));
    }

    cout << PI * r2 * r2 - PI * r1 * r1 << "\n";

    return 0;
}