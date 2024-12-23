#include <bits/stdc++.h>

using namespace std;

#define int long long

// Change it
// typedef int int;

struct segment_tree {
    int size;
    vector <int> values;

    // Change it
    int NEUTRAL_ELEMENT = 0LL;

    // Change it
    int merge(int a, int b) {
        return a + b;
    }

    // Change it
    int single(int v) {
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

    int calculate(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return NEUTRAL_ELEMENT;
        }
        else if (lx >= l && rx <= r) {
            return values[x];
        }
        else {
            int mid = lx + (rx - lx) / 2;

            int it1 = calculate(l, r, 2 * x + 1, lx, mid);
            int it2 = calculate(l, r, 2 * x + 2, mid, rx);

            return merge(it1, it2); // Update if necessary
        }
    }

    int calculate(int l, int r) {
        return calculate(l, r, 0, 0, size);
    }
};

void solve()
{
    int n, x, y, l, r, i;
    int sum, s = 0;
    segment_tree st;

    cin >> n >> x >> y;

    vector <int> v(n, 0), indices(n), sorted_v;
    vector <pair <int, int>> temp;

    st.build(v);

    for (auto &it : v) {
        cin >> it;
    }

    sorted_v = v;
    sum = accumulate(v.begin(), v.end(), 0LL);

    sort(sorted_v.begin(), sorted_v.end());

    for (i = 0; i < n; i++) {
        temp.push_back({v[i], i});
    }

    sort(temp.begin(), temp.end());

    for (i = 0; i < n; i++) {
        indices[temp[i].second] = i;
    }

    for (i = 0; i < n; i++) {
        r = sum - x - v[i];
        l = sum - y - v[i];

        st.set(indices[i], 1);

        int low = lower_bound(sorted_v.begin(), sorted_v.end(), l) - sorted_v.begin();
        int high = upper_bound(sorted_v.begin(), sorted_v.end(), r) - sorted_v.begin() - 1;

        if (high < low) {
            continue;
        }

        int temp_s = high - low + 1 - st.calculate(low, high + 1);

        s += temp_s;
    }

    cout << s << "\n";
}

int32_t main()
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