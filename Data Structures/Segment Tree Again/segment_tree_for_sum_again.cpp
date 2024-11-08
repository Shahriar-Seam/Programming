#include <bits/stdc++.h>

using namespace std;

#define int long long

struct segment_tree {
    int size;
    vector <long long> sums;

    void init(int n) {
        size = n;

        sums.assign(2 * size, 0LL);
    }

    void build(vector <int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < v.size()) {
                sums[x] = v[lx];
            }

            return;
        }
        else {
            int mid = lx + (rx - lx) / 2;

            (2 * x + 1 < 2 * size) ? build(v, 2 * x + 1, lx, mid) : build(v, x + 1, lx, mid);
            (2 * x + 2 < 2 * size) ? build(v, 2 * x + 2, mid, rx) : build(v, x + 2, mid, rx);

            sums[x] += (2 * x + 1 < 2 * size) ? sums[2 * x + 1] : sums[x + 1];
            sums[x] += (2 * x + 2 < 2 * size) ? sums[2 * x + 2] : sums[x + 2];
        }
    }

    void build(vector <int> &v) {
        init(v.size());

        build(v, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = v;

            return;
        }

        int mid = lx + (rx - lx) / 2;

        if (i < mid) {
            (2 * x + 1 < 2 * size) ? set(i, v, 2 * x + 1, lx, mid) : set(i, v, x + 1, lx, mid);
        }
        else {
            (2 * x + 2 < 2 * size) ? set(i, v, 2 * x + 2, mid, rx) : set(i, v, x + 2, mid, rx);
        }

        sums[x] = (2 * x + 1 < 2 * size) ? sums[2 * x + 1] : sums[x + 1];
        sums[x] += (2 * x + 2 < 2 * size) ? sums[2 * x + 2] : sums[x + 2];
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    long long sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return 0LL;
        }
        else if (lx >= l && rx <= r) {
            return sums[x];
        }
        else {
            int mid = lx + (rx - lx) / 2;

            long long sum_left = (2 * x + 1 < 2 * size) ? sum(l, r, 2 * x + 1, lx, mid) : sum(l, r, x + 1, lx, mid);
            long long sum_right = (2 * x + 2 < 2 * size) ? sum(l, r, 2 * x + 2, mid, rx) : sum(l, r, x + 2, mid, rx);

            return sum_left + sum_right;
        }
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }

    void show() {
        for (int i = 0; i < sums.size(); i++) {
            cout << sums[i] << " ";
        }

        cout << "\n";
    }
};

int32_t main()
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

            cout << st.sum(l, r) << "\n";
        }  
    }

    return 0;
}