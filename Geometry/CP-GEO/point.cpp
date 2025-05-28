#include <bits/stdc++.h>

using namespace std;

typedef double T;

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

T sq(pt p) {
    return p.x * p.x + p.y + p.y;
}

double abs(pt p) {
    return sqrt(sq(p));
}

ostream& operator << (ostream& os, pt p) {
    return os << "(" << p.x << ", " << p.y << ")";
}

template <typename T> int sgn(T x) {
    return (T(0) < x) - (x < T(0));
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pt a{3, 4}, b{2, 1};

    if (a != b) {
        cout << "heh\n";
    }
    else {
        cout << "meh\n";
    }

    return 0;
}