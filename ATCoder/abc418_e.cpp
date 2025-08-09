#include <bits/stdc++.h>

using namespace std;

typedef double T; // Define type alias for coordinates
const double PI = acos(-1); // Constant for pi
const double eps = 1e-9;

struct double_cmp {
    bool operator() (const double &a, const double &b) const {
        return a + eps < b;
    }
};

// Point structure representing 2D vectors or coordinates
struct pt {
    T x, y;

    // Vector addition
    pt operator + (pt p) {
        return {x + p.x, y + p.y};
    }

    // Vector subtraction
    pt operator - (pt p) {
        return {x - p.x, y - p.y};
    }

    // Scalar multiplication
    pt operator * (T d) {
        return {x * d, y * d};
    }

    // Scalar division
    pt operator / (T d) {
        return {x / d, y / d};
    }

    // Determines which half-plane the point lies in:
    // -1 for lower half, 0 on positive x-axis, 1 for upper half
    int pos() const {
        if (y < 0) return -1;
        if (y == 0 && x >= 0) return 0;
        return 1;
    }

    // Sorts by polar angle with respect to origin (for CCW ordering)
    bool operator < (pt r) const {
        if (pos() != r.pos()) return pos() < r.pos();
        return x * r.y - y * r.x > 0; // cross product > 0 ⇒ this comes before r
    }
};

// Equality comparison
bool operator == (pt a, pt b) {
    return a.x == b.x && a.y == b.y;
}

// Inequality comparison
bool operator != (pt a, pt b) {
    return !(a == b);
}

// Square of the magnitude of a vector
T sq(pt p) {
    return p.x * p.x + p.y * p.y;
}

// Magnitude (length) of a vector
double abs(pt p) {
    return sqrt(sq(p));
}

// Input stream overload for pt
istream& operator >> (istream& is, pt &p) {
    return is >> p.x >> p.y;
}

// Output stream overload for pt
ostream& operator << (ostream& os, pt p) {
    return os << p.x << " " << p.y;
}

// Sign function: 1 if x > 0, -1 if x < 0, 0 if x == 0
template <typename T> int sgn(T x) {
    return (T(0) < x) - (x < T(0));
}

// Translate point p by vector v
pt translate(pt v, pt p) {
    return p + v;
}

// Scale point p with respect to center c by factor
pt scale(pt c, double factor, pt p) {
    return c + (p - c) * factor;
}

// Rotate point p by angle a (in radians) around origin
pt rot(pt p, double a) {
    return {p.x * cos(a) - p.y * sin(a), p.x * sin(a) + p.y * cos(a)};
}

// Perpendicular vector (rotated 90 degrees counter-clockwise)
pt perp(pt p) {
    return {-p.y, p.x};
}

// Dot product of two vectors
T dot(pt v, pt w) {
    return v.x * w.x + v.y * w.y;
}

// Check if two vectors are perpendicular
bool is_perp(pt v, pt w) {
    return dot(v, w) == 0;
}

// Angle between two vectors in radians
double angle(pt v, pt w) {
    double cos_theta = dot(v, w) / abs(v) / abs(w);
    return acos(max(-1.0, min(1.0, cos_theta))); // Clamp to avoid errors
}

// 2D cross product (signed area of the parallelogram)
T cross(pt v, pt w) {
    return v.x * w.y - v.y * w.x;
}

// Linear transformation mapping p→fp and q→fq, then applied to r
pt linear_transform(pt p, pt q, pt r, pt fp, pt fq) {
    pt pq = q - p;
    pt num{cross(pq, fq - fp), dot(pq, fq - fp)};
    return fp + pt{cross(r - p, num), dot(r - p, num)} / sq(pq);
}

// Orientation of triplet (a, b, c)
// >0 if counter-clockwise, <0 if clockwise, 0 if collinear
T orient(pt a, pt b, pt c) {
    return cross(b - a, c - a);
}

// Check if point p lies within angle ∠bac
bool is_in_angle(pt a, pt b, pt c, pt p) {
    assert(orient(a, b, c) != 0); // Must be a valid (non-degenerate) angle
    if (orient(a, b, c) < 0) swap(b, c); // Ensure CCW orientation
    return orient(a, b, p) >= 0 && orient(a, c, p) <= 0;
}

// Oriented angle ∠bac in [0, 2π] radians
double oriented_angle(pt a, pt b, pt c) {
    if (orient(a, b, c) >= 0) {
        return angle(b - a, c - a);
    } else {
        return 2 * PI - angle(b - a, c - a);
    }
}

// Check if polygon defined by point list p is convex
bool is_convex(vector <pt> p) {
    bool pos = false, neg = false;
    int i, n = p.size();
    for (i = 0; i < n; i++) {
        T o = orient(p[i], p[(i + 1) % n], p[(i + 2) % n]);
        if (o > 0) pos = true;
        if (o < 0) neg = true;
    }
    return !(pos && neg); // Must all turn in same direction
}

// Line structure representing a 2D line in ax + by = c form using vector form
struct line {
    pt v; T c;

    line() {}

    // Construct line from direction vector v and constant c
    line(pt v, T c) : v(v), c(c) {}

    // Construct line from equation ax + by = c
    line(T a, T b, T c) : v({b, -a}), c(c) {}

    // Construct line through points p and q
    line(pt p, pt q) : v(q - p), c(cross(v, p)) {}

    // Signed distance from point p to line (not normalized)
    T side(pt p) {
        return cross(v, p) - c;
    }

    // Euclidean distance from point p to line
    double dist(pt p) {
        return abs(side(p)) / abs(v);
    }

    // Square of the distance from point p to line
    double sq_dist(pt p) {
        return side(p) * side(p) / (double) sq(v);
    }

    // Returns line perpendicular to this one passing through point p
    line perp_through(pt p) {
        return {p, p + perp(v)};
    }

    // Compare projections of points p and q along line direction
    bool cmp_proj(pt p, pt q) {
        return dot(v, p) < dot(v, q);
    }

    // Translate line by vector t
    line translate(pt t) {
        return {v, c + cross(v, t)};
    }

    // Shift line to the left by distance dist (left defined by direction of v)
    line shift_left(double dist) {
        return {v, c + dist * abs(v)};
    }

    // Compute intersection point of lines l1 and l2 (if not parallel)
    bool inter(line l1, line l2, pt &out) {
        T d = cross(l1.v, l2.v);
        if (d == 0) return false; // No intersection (parallel lines)
        out = (l2.v * l1.c - l1.v * l2.c) / d;
        return true;
    }

    // Project point p onto the line
    pt proj(pt p) {
        return p - perp(v) * side(p) / sq(v);
    }

    // Reflect point p across the line
    pt refl(pt p) {
        return p - perp(v) * 2 * side(p) / sq(v);
    }
};

struct item {
    vector <pt> p;

    item() {};

    item(pt a, pt b, pt c, pt d) : p() {
        p = {a, b, c, d};

        sort(p.begin(), p.end());
    }

    bool operator < (item it) const {
        return p < it.p;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, j, count = 0;
    pt p1{1, 0}, p2{-1, 0};

    cin >> n;

    vector <pt> v(n);
    vector <pt> l;
    map <T, vector <pair <pt, pt> > , double_cmp> mp;
    set <item> s;

    for (auto &it : v) {
        cin >> it;
    }
    
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            l.push_back(v[j] - v[i]);

            mp[min(angle(l.back(), p1), angle(l.back(), p2))].push_back({v[i], v[j]});
        }
    }

    for (auto &it : mp) {
        cout << it.first * 180 / PI << " " << it.second.size() << "\n";
        for (i = 0; i < it.second.size(); i++) {
            for (j = i + 1; j < it.second.size(); j++) {
                if (s.find(item(it.second[i].first, it.second[i].second, it.second[j].first, it.second[j].second)) == s.end()) {
                    count++;

                    s.insert(item(it.second[i].first, it.second[i].second, it.second[j].first, it.second[j].second));
                }
            }
        }
    }

    cout << s.size() << "\n";

    cout << count << "\n";

    return 0;
}