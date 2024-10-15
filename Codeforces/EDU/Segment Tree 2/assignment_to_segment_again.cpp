#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
    int size;
    vector <long long> operations;
    long long NO_OPERATION = LONG_LONG_MAX;

    void apply_operation(long long &a, long long b) {
        a = (b == NO_OPERATION ? a : b);
    }

    void propagate(int x, int lx, int rx) {
        if (rx - lx == 1) {
            return;
        }
        else {
            apply_operation(operations[2 * x + 1], operations[x]);
            apply_operation(operations[2 * x + 2], operations[x]);

            operations[x] = NO_OPERATION;
        }
    }

    void init(int n) {
        size = 1;

        while (size < n) {
            size *= 2;
        }

        operations.resize(2 * size, 0LL);
    }

    void modify(int l, int r, int v, int x, int lx, int rx) {
        propagate(x, lx, rx);

        if (lx >= r || l >= rx) {
            return;
        }
        else if (lx >= l && rx <= r) {
            apply_operation(operations[x], v);

            return;
        }

        int mid = (lx + rx) / 2;

        modify(l, r, v, 2 * x + 1, lx, mid);
        modify(l, r, v, 2 * x + 2, mid, rx);
    }

    void modify(int l, int r, int v) {
        modify(l, r, v, 0, 0, size);
    }

    long long get(int i, int x, int lx, int rx) {
        propagate(x, lx, rx);

        if (rx - lx == 1) {
            return operations[x];
        }

        int mid = (lx + rx) / 2;

        if (i < mid) {
            return get(i, 2 * x + 1, lx, mid);
        }
        else {
            return get(i, 2 * x + 2, mid, rx);
        }
    }

    long long get(int i) {
        return get(i, 0, 0, size);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    segment_tree st;

    cin >> n >> m;

    st.init(n);

    while (m--) {
        int op;

        cin >> op;

        if (op == 1) {
            int l, r, v;

            cin >> l >> r >> v;

            st.modify(l, r, v);
        }
        else {
            int i;

            cin >> i;

            cout << st.get(i) << "\n";
        }
    }

    return 0;
}