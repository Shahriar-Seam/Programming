#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
    int size;
    vector <long long> sums;

    void build(vector <int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < v.size()) {
                sums[x] = v[lx];
            }

            return;
        }
        else {
            int mid = lx + (rx - lx) / 2;

            build(v, 2 * x + 1, lx, mid);
            build(v, 2 * x + 2, mid, rx);

            sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        }
    }

    void build(vector <int> &v) {
        size = 1;

        while (size < v.size()) {
            size *= 2;
        }

        sums.assign(2 * size, 0);

        build(v, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = v;

            return;
        }
        else {
            int mid = lx + (rx - lx) / 2;

            if (i < mid) {
                set(i, v, 2 * x + 1, lx, mid);
            }
            else {
                set(i, v, 2 * x + 2, mid, rx);
            }

            sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
        }
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return 0;
        }
        else if (lx >= l && rx <= r) {
            return sums[x];
        }

        int mid = lx + (rx - lx) / 2;

        long long sum_left = sum(l, r, 2 * x + 1, lx, mid);
        long long sum_right = sum(l, r, 2 * x + 2, mid, rx);

        return sum_left + sum_right;
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }

    // Debug Function
    void print_tree() {
        for (auto it : sums) {
            cout << it << " ";
        }

        cout << "\n";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, op;
    segment_tree st;

    cin >> n >> m;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    st.build(v);

    while (m--) {
        cin >> op;

        if (op == 1) {
            int i, v;

            cin >> i >> v;

            st.set(i, v);
        }
        else {
            int l, r;

            cin >> l >> r;

            cout << st.sum(l, r) << '\n';
        }
    }

    st.print_tree();

    return 0;
}