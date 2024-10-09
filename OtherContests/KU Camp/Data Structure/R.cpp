#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
    vector <int> mins;
    int size;

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
        size = 1;

        while (size < v.size()) {
            size *= 2;
        }

        mins.resize(size * 2, INT_MAX);

        build(v, 0, 0, size);
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

    int n, q, i, j;
    segment_tree st;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    st.build(v);

    cin >> q;

    while (q--) {
        cin >> i >> j;

        cout << st.minimum(i, j + 1) << "\n";
    }

    return 0;
}