#include <bits/stdc++.h>

using namespace std;

// Change it
typedef int item;

struct segment_tree {
    int size;
    vector <item> values;

    // Change it
    item NEUTRAL_ELEMENT = 0;

    // Change it
    item merge(item a, item b) {
        return a + b;
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

        values.resize(size * 2);
    }

    void build(vector <int> &a, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < (int) a.size()) {
                values[x] = single(a[lx]); // Update if necessary
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
        for (auto it : values) {
            cout << it << " ";
        }
    }
};

vector <int> calc(vector <int> &v)
{
    int n = v.size() / 2, i;
    vector <int> a(2 * n, 0), ind(n, -1), counter(n, 0);
    segment_tree st;

    st.build(a);

    for (i = 0; i < 2 * n; i++) {
        if (ind[v[i] - 1] != -1) {
            counter[v[i] - 1] = st.calculate(ind[v[i] - 1] + 1, i + 1);

            st.set(ind[v[i] - 1], 0);
        }
        else {
            ind[v[i] - 1] = i;

            st.set(i, 1);
        }
    }

    return counter;
}

vector <int> combine(vector <int> &a, vector <int> &b)
{
    int i, n = a.size();
    vector <int> c(n);

    for (i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }

    return c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i;
    segment_tree st;

    cin >> n;

    vector <int> v(2 * n), temp, counter;

    for (auto &it : v) {
        cin >> it;
    }
    
    temp = v;

    reverse(v.begin(), v.end());

    temp = calc(temp);
    v = calc(v);

    counter = combine(temp, v);

    for (auto it : counter) {
        cout << it << " ";
    }

    return 0;
}