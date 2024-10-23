#include <bits/stdc++.h>

using namespace std;

typedef struct {
    long long val = 0;
    long long prop = 0;
} item;

struct segment_tree {
    vector <item> values;
    int size;

    void init(int n) {
        size = 1;

        while (size < n) {
            size *= 2;
        }

        values.resize(2 * size);
    }

    void build(vector <int> v, int x, int lx, int rx) {
        if (rx - lx == 0) {
            if (lx < v.size()) {
                values[x].val = v[lx];
            }

            return;
        }

        int mid = (lx + rx) / 2;

        build(v, 2 * x + 1, lx, mid);
        build(v, 2 * x + 2, mid, rx);

        values[x].val = values[2 * x + 1].val + values[2 * x + 2].val;
    }

    void build(vector <int> v) {
        init(v.size());

        build(v, 0, 0, size);
    }

    void update(int l, int r, int v, int x, int lx, int rx) {
        if (values[x].prop) {
            values[x].val += ((rx - lx) * values[x].prop);

            if (rx - lx > 1) {
                values[2 * x + 1].prop += values[x].prop;
                values[2 * x + 2].prop += values[x].prop;
            }
            values[x].prop = 0;
        }
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            values[x].val += ((rx - lx) * 1LL * v);

            if (rx - lx > 1) {
                values[2 * x + 1].prop += 1LL * v;
                values[2 * x + 2].prop += 1LL * v;
            }

            return;
        }

        int mid = (lx + rx) / 2;

        update(l, r, v, 2 * x + 1, lx, mid);
        update(l, r, v, 2 * x + 2, mid, rx);

        values[x].val = values[2 * x + 1].val + values[2 * x + 2].val;
    }

    void update(int l, int r, int v) {
        update(l, r, v, 0, 0, size);
    }

    long long query(int l, int r, int x, int lx, int rx) {
        if (values[x].prop) {
            values[x].val += ((rx - lx) * values[x].prop);

            if (rx - lx > 1) {
                values[2 * x + 1].prop += values[x].prop;
                values[2 * x + 2].prop += values[x].prop;
            }

            values[x].prop = 0;
        }
        if (lx >= r || rx <= l) {
            return 0;
        }
        if (lx >= l && rx <= r) {
            return values[x].val;
        }

        int mid = (lx + rx) / 2;

        return query(l, r, 2 * x + 1, lx, mid) + query(l, r, 2 * x + 2, mid, rx);
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, size);
    }
};

void solve()
{
    int n, c;
    segment_tree st;

    cin >> n >> c;

    st.init(n);

    while (c--) {
        int op;

        cin >> op;

        if (op == 0) {
            int p, q, v;

            cin >> p >> q >> v;

            st.update(p - 1, q, v);
        }
        else {
            int p, q;

            cin >> p >> q;

            cout << st.query(p - 1, q) << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;

    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}