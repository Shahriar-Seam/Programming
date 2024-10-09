#include <bits/stdc++.h>

using namespace std;

struct item {
    int m, c;
};

struct segment_tree {
    int size;
    vector <item> values;

    item NEUTRAL_ELEMENT = {INT_MAX, 0};

    item merge(item a, item b) {
        if (a.m < b.m) {
            return a;
        }
        else if (a.m > b.m) {
            return b;
        }
        else {
            return {a.m, a.c + b.c};
        }
    }

    item single(int v) {
        return {v, 1};
    }

    void init(int n) {
        size = 1;

        while (size < n) {
            size *= 2;
        }

        values.resize(size * 2);
    }

    void build(vector <int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int) a.size()) {
                values[x] = single(a[lx]);
            }

            return;
        }

        int mid = lx + (rx - lx) / 2;

        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid, rx);

        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void build(vector <int> &a) {
        init(a.size());

        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            values[x] = single(v);

            return;
        }

        int mid = lx + (rx - lx) / 2;

        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }

        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }

    void set(int i, int v) {
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

            return merge(it1, it2);
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

    int n, m;
    segment_tree st;

    cin >> n >> m;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    st.build(v);

    while (m--) {
        int op;

        cin >> op;

        if (op == 1) {
            int i, v;

            cin >> i >> v;

            st.set(i, v);
        }
        else {
            int l, r;

            cin >> l >> r;

            item it = st.calculate(l, r);

            cout << it.m << " " << it.c << "\n";
        }
    }

    return 0;
}