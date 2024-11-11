#include <bits/stdc++.h>

using namespace std;

// Change it
#define item long long

struct segment_tree {
    int size;
    vector <item> values;

    // Change it
    item NEUTRAL_ELEMENT = (1LL << 33) - 1;

    // Change it
    item merge(item a, item b) {
        return a & b;
    }

    // Change it
    item single(int v) {
        return v;
    }

    void init(int n) {
        size = 1;

        while (size < n) {
            size *= 2;
        }

        values.resize(size * 2, NEUTRAL_ELEMENT);
    }

    void build(vector <int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int) a.size()) {
                if (lx != 0) {
                    values[x] = single(a[lx]); // Update if necessary
                }
            }

            return;
        }

        int mid = lx + (rx - lx) / 2;

        build(a, 2 * x + 1, lx, mid);
        build(a, 2 * x + 2, mid, rx);

        values[x] = merge(values[2 * x + 1], values[2 * x + 2]); // Update if necessary
    }

    void build(vector <int> &a) {
        init(a.size());

        build(a, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            values[x] = single(v); // Update if necessary

            return;
        }

        int mid = lx + (rx - lx) / 2;

        if (i < mid) {
            set(i, v, 2 * x + 1, lx, mid);
        }
        else {
            set(i, v, 2 * x + 2, mid, rx);
        }

        values[x] = merge(values[2 * x + 1], values[2 * x + 2]); // Update if necessary
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    item calculate(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return NEUTRAL_ELEMENT;
        }
        else if (lx >= l && rx <= r) {
            return values[x];
        }
        else {
            int mid = lx + (rx - lx) / 2;

            item it1 = calculate(l, r, 2 * x + 1, lx, mid);
            item it2 = calculate(l, r, 2 * x + 2, mid, rx);

            return merge(it1, it2); // Update if necessary
        }
    }

    item calculate(int l, int r) {
        return calculate(l, r, 0, 0, size);
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
    int n, i, j;
    segment_tree st;

    cin >> n;

    vector <int> v(n + 1, 0), f_or(n + 2, 0), l_or(n + 2, 0);

    for (i = 1; i <= n; i++) {
        cin >> v[i];
    }

    if (count(v.begin(), v.end(), 1) == n) {
        for (i = 1; i <= n; i++) {
            cout << v[i];

            if (i != n) {
                cout << " ";
            }
            else {
                cout << "\n";
            }
        }

        return;
    }

    for (i = 1; i <= n; i++) {
        f_or[i + 1] = f_or[i] | v[i];
    }

    for (i = n; i > 0; i--) {
        l_or[i - 1] = l_or[i] | v[i];
    }

    st.build(v);

    for (i = 1; i < (n + 1) / 2; i++) {
        cout << f_or[n + 1] << " ";
    }

    for (i, j = n / 2 + 1; i <= n; i++, j--) {
        cout << ((f_or[j] | l_or[n + 1 - j]) & st.calculate(j, n + 1 - j + 1));

        if (i != n) {
            cout << " ";
        }
        else {
            cout << "\n";
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