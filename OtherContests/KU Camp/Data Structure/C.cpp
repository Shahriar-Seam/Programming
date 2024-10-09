#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
    vector <long long> sums;
    int size;

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

        sums.assign(size * 2, 0);

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
        if (l >= rx || r <= lx) {
            return 0;
        }
        else if (lx >= l && rx <= r) {
            return sums[x];
        }
        else {
            int mid = lx + (rx - lx) / 2;

            long long sum_left = sum(l, r, 2 * x + 1, lx, mid);
            long long sum_right = sum(l, r, 2 * x + 2, mid, rx);

            return sum_left + sum_right;
        }
    }

    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }
};

void solve()
{
    int n, q;
    segment_tree st;

    cin >> n >> q;

    vector <int> arr(n);

    for (auto &it : arr) {
        cin >> it;
    }

    st.build(arr);

    while (q--) {
        int op;

        cin >> op;

        if (op == 1) {
            int i;

            cin >> i;

            cout << arr[i] << "\n";

            arr[i] = 0;

            st.set(i, arr[i]);
        }
        else if (op == 2) {
            int i, v;

            cin >> i >> v;

            arr[i] += v;

            st.set(i, arr[i]);
        }
        else {
            int i, j;

            cin >> i >> j;

            cout << st.sum(i, j + 1) << "\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        cout << "Case " << i << ":\n";
        
        solve();
    }

    return 0;
}