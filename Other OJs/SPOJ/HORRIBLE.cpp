#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
    int size;
    vector <long long> operations;
    long long NO_OPERATION = LONG_LONG_MAX;

    void apply_operation(long long &a, long long b) {
        if (b == NO_OPERATION) {
            return;
        }
        else {
            a = a + b;
        }
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

    long long sum(int l, int r, int x, int lx, int rx) {
        propagate(x, lx, rx);

        if (rx - lx == 1) {
            return operations[x] == NO_OPERATION ? 0 : operations[x];
        }

        if (lx >= r || l >= rx) {
            return 0;
        }
        else if (lx >= l && rx <= r) {
            return operations[x] == NO_OPERATION ? 0 : operations[x];
        }

        int mid = (lx + rx) / 2;

        long long sum_left = sum(l, r, 2 * x + 1, lx, mid);
        long long sum_right = sum(l, r, 2 * x + 2, mid, rx);

        return sum_left + sum_right;
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
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

            st.modify(p - 1, q, v);
        }
        else {
            int p, q;

            cin >> p >> q;

            cout << st.sum(p - 1, q) << "\n";
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