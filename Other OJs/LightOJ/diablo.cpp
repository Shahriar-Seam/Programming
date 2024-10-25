#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
    vector <int> values;
    int size;

    void init(int n, int q) {
        size = 1;

        while (size < (n + q)) {
            size *= 2;
        }

        values.assign(size * 2, 0);
    }

    void build(int n, int q, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < n) {
                values[x] = 1;
            }

            return;
        }

        int mid = (lx + rx) / 2;

        build(n, q, 2 * x + 1, lx, mid);
        build(n, q, 2 * x + 2, mid, rx);

        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }

    void build(int n, int q) {
        init(n, q);

        build(n, q, 0, 0, size);
    }

    void add(int i, int x, int lx, int rx) {
        if (rx - lx == 1) {
            values[x] = 1;

            return;
        }

        int mid = (lx + rx) / 2;

        if (i < mid) {
            add(i, 2 * x + 1, lx, mid);
        }
        else {
            add(i, 2 * x + 2, mid, rx);
        }

        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }

    void add(int i) {
        add(i, 0, 0, size);
    }

    int get(int k, int x, int lx, int rx) {
        if (rx - lx == 1) {
            values[x] = 0;
            return lx;
        }

        int mid = (lx + rx) / 2;

        int sum_left = values[2 * x + 1];

        int index = 0;

        if (k < sum_left) {
            index = get(k, 2 * x + 1, lx, mid);
        }
        else {
            index = get(k - sum_left, 2 * x + 2, mid, rx);
        }

        values[x] = values[2 * x + 1] + values[2 * x + 2];

        return index;
    }

    int get(int k) {
        return get(k, 0, 0, size);
    }

    void show() {
        int i, j, k = 0;

        for (i = 0; i <= log2(size); i++) {
            for (j = 0; j < (1 << i); j++) {
                cout << values[k++] << " ";
            }

            cout << "\n";
        }
    }
};

void solve()
{
    int n, q;
    segment_tree st;

    cin >> n >> q;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    st.build(n, q);

    while (q--) {
        char op;

        cin >> op;

        if (op == 'a') {
            int p;

            cin >> p;

            st.add(v.size());

            v.push_back(p);
        }
        else {
            int k, index;

            cin >> k;

            index = st.get(k - 1);

            if (index < v.size()) {
                cout << v[index] << "\n";
            }
            else {
                cout << "none\n";
            }
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