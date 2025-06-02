#include <bits/stdc++.h>

using namespace std;

#define int long long
typedef double T;
const double PI = acos(-1);

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    template <typename T>
    size_t operator()(const T& x) const {
        return hash_combine(x);
    }

private:
    static const uint64_t FIXED_RANDOM;

    // Arithmetic types (int, long long, etc.)
    template <typename T>
    static typename enable_if<is_integral<T>::value, size_t>::type
    hash_combine(const T& x) {
        return splitmix64(x + FIXED_RANDOM);
    }

    // string specialization
    static size_t hash_combine(const string& s) {
        size_t h = 0;
        for (char c : s) {
            h = h * 31 + c;
        }
        return splitmix64(h + FIXED_RANDOM);
    }

    // pair
    template <typename T1, typename T2>
    static size_t hash_combine(const pair<T1, T2>& p) {
        size_t h1 = custom_hash{}(p.first);
        size_t h2 = custom_hash{}(p.second);
        return h1 ^ (h2 << 1);
    }

    // tuple
    template <typename Tuple, size_t Index = 0>
    static typename enable_if<Index == tuple_size<Tuple>::value, size_t>::type
    hash_tuple(const Tuple&) {
        return 0;
    }

    template <typename Tuple, size_t Index = 0>
    static typename enable_if<Index < tuple_size<Tuple>::value, size_t>::type
    hash_tuple(const Tuple& t) {
        size_t h1 = custom_hash{}(get<Index>(t));
        size_t h2 = hash_tuple<Tuple, Index + 1>(t);
        return h1 ^ (h2 << 1);
    }

    template <typename... Ts>
    static size_t hash_combine(const tuple<Ts...>& t) {
        return hash_tuple(t);
    }

    // Iterable containers (e.g., vector, set, unordered_set)
    template <typename T>
    static typename enable_if<!is_integral<T>::value &&
                              !is_same<T, string>::value &&
                              !is_same<T, tuple<typename T::value_type>>::value &&
                              !is_same<T, pair<typename T::first_type, typename T::second_type>>::value,
                              size_t>::type
    hash_combine(const T& container) {
        size_t h = 0;
        for (const auto& x : container) {
            h ^= custom_hash{}(x) + 0x9e3779b9 + (h << 6) + (h >> 2);
        }
        return h;
    }
};

const uint64_t custom_hash::FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();

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
    return os << "(" << p.x << ", " << p.y << ")";
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
    assert(p.x != 0 || p.y != 0);

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

    int n, i, j, x, y, g, count = 0;

    cin >> n;

    vector <pt> p(n);

    for (auto &it : p) {
        cin >> it;
    }

    count = (n * (n - 1) * (n - 2)) / 6;

    for (i = 0; i < n; i++) {
        unordered_map <pair <int, int>, int, custom_hash> mp;

        for (j = i + 1; j < n; j++) {
            x = p[i].x - p[j].x;
            y = p[i].y - p[j].y;

            g = gcd(x, y);

            x /= g;
            y /= g;

            if (y < 0 || (y == 0 && x < 0)) {
                x = -x;
                y = -y;
            }

            mp[{x, y}]++;
        }

        for (auto &it : mp) {
            count -= (it.second * (it.second - 1)) / 2;
        }
    }

    cout << count << "\n";

    return 0;
}