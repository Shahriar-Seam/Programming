#include <bits/stdc++.h>

using namespace std;

// Change it
struct item {
    int a, b, c, d;
};

int r;

struct segment_tree {
    int size;
    vector <item> values;

    // Change it
    item NEUTRAL_ELEMENT = {1, 0, 0, 1};

    // Change it
    item merge(item a, item b) {
        return {
            (a.a * b.a + a.b * b.c) % r,
            (a.a * b.b + a.b * b.d) % r,
            (a.c * b.a + a.d * b.c) % r,
            (a.c * b.b + a.d * b.d) % r
        };
    }

    // Change it
    item single(item v) {
        return v;
    }

    void init(int n) {
        size = 1;

        while (size < n) {
            size *= 2;
        }

        values.resize(size * 2);
    }

    void build(vector <item> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int) a.size()) {
                values[x] = single(a[lx]); // Update if necessary
            }

            return;
        }

        int mid = lx + (rx - lx) / 2;

        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid, rx);

        values[x] = merge(values[2 * x + 1], values[2 * x + 2]); // Update if necessary
    }

    void build(vector <item> &a) {
        init(a.size());

        build(a, 0, 0, size);
    }

    void set(int i, item v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            values[x] = single(v); // Update if necessary

            return;
        }

        int mid = lx + (rx - lx) / 2;

        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }

        values[x] = merge(values[2 * x + 1], values[2 * x + 2]); // Update if necessary
    }

    void set(int i, item v) {
        set(i, v, 0, 0, size);
    }

    item calculate(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return NEUTRAL_ELEMENT;
        }
        else if (lx >= l && rx <= r) {
            return values[x];
        }
        else {
            int mid = lx + (rx - lx) / 2;

            item it1 = calculate(l, r, 2 * x + 1, lx, mid);
            item it2 = calculate(l, r, 2 * x + 2, mid, rx);

            return merge(it1, it2); // Update if necessary
        }
    }

    item calculate(int l, int r) {
        return calculate(l, r, 0, 0, size);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, j;
    segment_tree st;

    cin >> r >> n >> m;

    vector <item> v(n);

    for (i = 0; i < n; i++) {
        cin >> v[i].a >> v[i].b >> v[i].c >> v[i].d;
    }

    st.build(v);

    while (m--) {
        cin >> i >> j;

        item it = st.calculate(i - 1, j);

        cout << it.a << " " << it.b << "\n";
        cout << it.c << " " << it.d << "\n";
        cout << "\n";
    }

    return 0;
}