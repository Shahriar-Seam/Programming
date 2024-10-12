#include <bits/stdc++.h>

using namespace std;

// Change it
struct item {
    long long count;
    map <int, int> frequency;
};

struct segment_tree {
    int size;
    vector <item> values;

    // Change it
    item NEUTRAL_ELEMENT = {0, map <int, int> ()};

    // Change it
    item merge(item a, item b) {
        item c = NEUTRAL_ELEMENT;

        c.count = a.count + b.count;

        for (auto i = a.frequency.rbegin(); i != a.frequency.rend(); i++) {
            for (auto j = b.frequency.begin(); j != b.frequency.end() && (*j).first < (*i).first; j++) {
                c.count += 1LL * (*i).second * (*j).second;
            }

            c.frequency[(*i).first] = (*i).second + b.frequency[(*i).first];
        }

        for (auto j = b.frequency.begin(); j != b.frequency.end(); j++) {
            if (c.frequency.find((*j).first) == c.frequency.end()) {
                c.frequency[(*j).first] = (*j).second;
            }
        }

        return c;
    }

    // Change it
    item single(int v) {
        item it = NEUTRAL_ELEMENT;

        it.count = 0;
        it.frequency[v] = 1;

        return it;
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
};

void solve()
{
    int n;
    segment_tree st;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    st.build(v);

    cout << st.calculate(0, n).count << "\n";
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