#include <bits/stdc++.h>

using namespace std;

struct data {
    long long sum, prefix, suffix, max_segment;

    static data make_data (long long val) {
        data d;

        d.sum = val;
        d.prefix = d.suffix = d.max_segment = max(0LL, val);

        return d;
    }

    data combine(data d) {
        data result;

        result.sum = this->sum + d.sum;
        result.prefix = max(this->prefix, this->sum + d.prefix);
        result.suffix = max(d.suffix, d.sum + this->suffix);
        result.max_segment = max(max(this->max_segment, d.max_segment), this->suffix + d.prefix);

        return result;
    }
};

struct segment_tree {
    int size;
    vector <struct data> sums;

    void build(vector <int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < v.size()) {
                sums[x] = data::make_data(v[lx]);
            }

            return;
        }
        else {
            int mid = lx + (rx - lx) / 2;

            build(v, 2 * x + 1, lx, mid);
            build(v, 2 * x + 2, mid, rx);

            sums[x] = sums[2 * x + 1].combine(sums[2 * x + 2]);
        }
    }

    void build(vector <int> &v) {
        size = 1;

        while (size < v.size()) {
            size *= 2;
        }

        sums.assign(2 * size, data::make_data(0LL));

        build(v, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            sums[x] = data::make_data(1LL * v);

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

            sums[x] = sums[2 * x + 1].combine(sums[2 * x + 2]);
        }
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    struct data maximum_sum_segment(int l, int r, int x, int lx, int rx) {
        if (l >= rx || r <= lx) {
            return data::make_data(0);
        }
        else if (lx >= l && rx <= r) {
            return sums[x];
        }
        else {
            int mid = lx + (rx - lx) / 2;

            struct data left = maximum_sum_segment(l, r, 2 * x + 1, lx, mid);
            struct data right = maximum_sum_segment(l, r, 2 * x + 2, mid, rx);

            return left.combine(right);
        }
    }

    struct data maximum_sum_segment(int l, int r) {
        return maximum_sum_segment(l, r, 0, 0, size);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i, v;
    segment_tree st;

    cin >> n >> m;

    vector <int> arr(n);

    for (auto &it : arr) {
        cin >> it;
    }

    st.build(arr);

    cout << st.maximum_sum_segment(0, n).max_segment << "\n";

    while (m--) {
        cin >> i >> v;

        st.set(i, v);

        cout << st.maximum_sum_segment(0, n).max_segment << "\n";
    }

    return 0;
}