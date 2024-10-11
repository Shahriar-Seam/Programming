#include <bits/stdc++.h>

using namespace std;

// Change it
struct item {
    int leftMost, rightMost, frLeftMost, frRightMost, ans;
};

struct segment_tree {
    int size;
    vector <item> values;

    // Change it
    item NEUTRAL_ELEMENT = {0, 0, 0, 0, 0};

    // Change it
    item merge(item a, item b) {
        if (a.ans == 0) {
            return b;
        }
        else if (b.ans == 0) {
            return a;
        }
        else if (a.leftMost == b.rightMost) {
            return {
                a.leftMost,
                b.rightMost,
                a.frLeftMost + b.frLeftMost,
                a.frRightMost + b.frRightMost,
                a.ans + b.ans
            };
        }
        else if (a.leftMost == b.leftMost) {
            return {
                a.leftMost,
                b.rightMost,
                a.frLeftMost + b.frLeftMost,
                b.frRightMost,
                max(a.frLeftMost + b.frLeftMost, b.ans)
            };
        }
        else if (a.rightMost == b.rightMost) {
            return {
                a.leftMost,
                b.rightMost,
                a.frLeftMost,
                a.frRightMost + b.frRightMost,
                max(a.frRightMost + b.frRightMost, a.ans)
            };
        }
        else if (a.rightMost == b.leftMost) {
            return {
                a.leftMost,
                b.rightMost,
                a.frLeftMost,
                b.frRightMost,
                max({a.ans, b.ans, a.frRightMost + b.frLeftMost})
            };
        }
        else {
            return {
                a.leftMost,
                b.rightMost,
                a.frLeftMost,
                b.frRightMost,
                max(a.ans, b.ans)
            };
        }
    }

    // Change it
    item single(int v) {
        return {v, v, 1, 1, 1};
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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    
    while (1) {
        cin >> n;

        if (n == 0) {
            break;
        }

        segment_tree st;

        cin >> m;

        vector <int> v(n);

        for (auto &it : v) {
            cin >> it;
        }

        st.build(v);

        while (m--) {
            int i, j;

            cin >> i >> j;

            cout << st.calculate(i - 1, j).ans << "\n";
        }
    }

    return 0;
}