#include <bits/stdc++.h>

using namespace std;

typedef long long T;
const double PI = acos(-1);

struct pt {
    T x, y;

    pt operator + (pt p) {
        return {x + p.x, y + p.y};
    }

    pt operator - (pt p) {
        return {x - p.x, y - p.y};
    }

    pt operator * (T d) {
        return {x * d, y * d};
    }

    pt operator / (T d) {
        return {x / d, y / d};
    }
};

bool operator == (pt a, pt b) {
    return a.x == b.x && a.y == b.y;
}

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

// Stream input for points
istream& operator >> (istream& is, pt &p) {
    return is >> p.x >> p.y;
}

// Stream output for points
ostream& operator << (ostream& os, pt p) {
    return os << p.x << " " << p.y;
}

// Sign function: returns 1 if x>0, -1 if x<0, else 0
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

// Rotate point p by angle a (in radians) around origin (0,0)
pt rot(pt p, double a) {
    return {p.x * cos(a) - p.y * sin(a), p.x * sin(a) + p.y * cos(a)};
}

// Perpendicular vector (rotated 90 degrees CCW)
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

// Angle between two vectors (in radians)
double angle(pt v, pt w) {
    double cos_theta = dot(v, w) / abs(v) / abs(w);

    // Clamp cos_theta to [-1, 1] to avoid numeric issues with acos
    return acos(max(-1.0, min(1.0, cos_theta)));
}

// Cross product (2D vector "pseudo cross product" scalar)
T cross(pt v, pt w) {
    return v.x * w.y - v.y * w.x;
}

// Linear transform mapping points p, q to fp, fq respectively, applied to r
pt linear_transform(pt p, pt q, pt r, pt fp, pt fq) {
    pt pq = q - p;
    pt num{cross(pq, fq - fp), dot(pq, fq - fp)};

    return fp + pt{cross(r - p, num), dot(r - p, num)} / sq(pq);
}

// Orientation of triplet (a, b, c) via cross product
// >0: counter-clockwise, <0: clockwise, =0: collinear
T orient(pt a, pt b, pt c) {
    return cross(b - a, c - a);
}

// Check if point p lies inside the angle at a formed by b and c
bool is_in_angle(pt a, pt b, pt c, pt p) {
    assert(orient(a, b, c) != 0); // angle must be non-degenerate

    if (orient(a, b, c) < 0) {
        swap(b, c); // Ensure orientation is positive
    }

    return orient(a, b, p) >= 0 && orient(a, c, p) <= 0;
}

// Oriented angle at a formed by points b and c (in radians, [0, 2π])
double oriented_angle(pt a, pt b, pt c) {
    if (orient(a, b, c) >= 0) {
        return angle(b - a, c - a);
    }
    else {
        return 2 * PI - angle(b - a, c - a);
    }
}

// Check if polygon defined by points p is convex
bool is_convex(vector <pt> p) {
    bool pos = false, neg = false;
    int i, n = p.size();

    for (i = 0; i < n; i++) {
        T o = orient(p[i], p[(i + 1) % n], p[(i + 2) % n]);

        if (o > 0) {
            pos = true;
        }
        if (o < 0) {
            neg = true;
        }
    }

    // Polygon is convex if all turns are in the same direction
    return !(pos && neg);
}

// Helper to determine which half-plane the vector lies in for polar sorting
bool half(pt p) {
    // assert(p.x != 0 || p.y != 0);

    // true if vector is in upper half plane or on negative x-axis if y==0
    return p.y > 0 || (p.y == 0 && p.x < 0);
}

// Sort points by their polar angle around the origin (counterclockwise)
void polar_sort(vector <pt> &p) {
    sort(p.begin(), p.end(), [] (pt v, pt w) {
        // Compare half-plane first, then by cross product to order by angle
        return make_tuple(half(v), 0) < make_tuple(half(w), cross(v, w));
    });
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;

    cin >> n;

    vector <pt> p(n);

    for (auto &it : p) {
        cin >> it;
    }

    polar_sort(p);

    for (auto it : p) {
        cout << it << "\n";
    }

    return 0;
}