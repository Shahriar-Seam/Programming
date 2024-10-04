#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
    int size;
    vector <int> mins;

    void init(int n) {
        size = 1;

        while (size < n) {
            size *= 2;
        }

        mins.resize(size * 2, INT_MAX);
    }

    void build(vector <int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < v.size()) {
                mins[x] = v[lx];
            }

            return;
        }
        else {
            int mid = lx + (rx - lx) / 2;

            build(v, 2 * x + 1, lx, mid);
            build(v, 2 * x + 2, mid, rx);

            mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
        }
    }

    void build(vector <int> &v) {
        init(v.size());

        build(v, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            mins[x] = v;

            return;
        }

        int m = lx + (rx - lx) / 2;

        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        }
        else {
            set(i, v, 2 * x + 2, m, rx);
        }

        mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    int minimum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return INT_MAX;
        }
        else if (lx >= l && rx <= r) {
            return mins[x];
        }
        else {
            int mid = lx + (rx - lx) / 2;

            int min_left = minimum(l, r, 2 * x + 1, lx, mid);
            int min_right = minimum(l, r, 2 * x + 2, mid, rx);

            return min(min_left, min_right);
        }
    }

    int minimum(int l, int r) {
        return minimum(l, r, 0, 0, size);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    segment_tree st;

    cin >> n >> m;

    vector <int> nums(n);

    for (auto &it : nums) {
        cin >> it;
    }

    st.build(nums);

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

            cout << st.minimum(l, r) << "\n";
        }
    }

    return 0;
}