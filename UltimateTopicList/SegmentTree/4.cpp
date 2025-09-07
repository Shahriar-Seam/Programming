#include <bits/stdc++.h>

using namespace std;

struct Tree {
    typedef int T;

    static constexpr T unit = 0;

    T f(T a, T b) {
        return a + b;
    }

    vector <T> s;
    int n;

    Tree (int n = 0, T def = unit) : s(2 * n, def), n(n) {}

    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2; ) {
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
        }
    }

    T query(int b, int e) {
        T ra = unit, rb = unit;

        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b & 1) {
                ra = f(ra, s[b++]);
            }
            if (e & 1) {
                rb = f(s[--e], rb);
            }
        }

        return f(ra, rb);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, p;
    
    cin >> n;

    Tree t(n);

    for (i = 0; i < n; i++) {
        cin >> p;

        t.update(p - 1, 1);

        cout << t.query(p, n) << " ";
    }

    return 0;
}