#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
    int size;
    vector <long long> values;

    void init(int n) {
        size = 1;

        while (size < n) {
            size *= 2;
        }

        values.resize(size * 2, 0);
    }

    void add(int l, int r, int v, int x, int lx, int rx) {
        if (lx >= r || l >= rx) {
            return;
        }
        else if (lx >= l && rx <= r) {
            values[x] += v;

            return;
        }

        int mid = lx + (rx - lx) / 2;

        add(l, r, v, 2 * x + 1, lx, mid);
        add(l, r, v, 2 * x + 2, mid, rx);
    }

    void add(int l, int r, int v) {
        add(l, r, v, 0, 0, size);
    }

    long long get(int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            return values[x];
        }

        int mid = lx + (rx - lx) / 2;
        long long sum = 0;

        if (i < mid) {
            sum = get(i, 2 * x + 1, lx, mid);
        }
        else {
            sum = get(i, 2 * x + 2, mid, rx);
        }

        return sum + values[x];
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

            st.add(l, r, v);
        }
        else {
            int i;

            cin >> i;

            cout << st.get(i) << "\n";
        }
    }

    return 0;
}