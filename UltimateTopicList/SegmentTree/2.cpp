#include <bits/stdc++.h>

using namespace std;

typedef struct T {
    long long mn;
    long long cnt;
} T;

struct Tree {
    static constexpr T unit = {LONG_LONG_MAX, 1};

    T f(T a, T b) {
        if (a.mn < b.mn) {
            return a;
        }
        else if (a.mn > b.mn) {
            return b;
        }
        else {
            auto c = a;

            c.cnt += b.cnt;

            return c;
        }
    }

    vector <T> s;
    int n;

    Tree(int n = 0, T def = unit) : n(n), s(2 * n, def) {}

    void build(vector <T> &a) {
        for (int i = 0; i < n; i++) {
            s[n + i] = a[i];
        }

        for (int i = n - 1; i > 0; i--) {
            s[i] = f(s[i * 2], s[i * 2 + 1]);
        }
    }

    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2; ) {
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
        }
    }

    T query(int b, int e) {
        T ra = unit, rb = unit;

        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) {
                ra = f(ra, s[b++]);
            }
            if (e % 2) {
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

    T n, m, type, i, v, l, r;

    cin >> n >> m;

    vector <T> a(n);

    for (auto &it : a) {
        cin >> it.mn;

        it.cnt = 1;
    }

    Tree t(n);
    t.build(a);

    while (m--) {
        cin >> type;

        if (type == 1) {
            cin >> i >> v;

            t.update(i, v);
        }
        else {
            cin >> l >> r;

            cout << t.query(l, r) << "\n";
        }
    }

    return 0;
}