#include <bits/stdc++.h>

using namespace std;

struct segment_tree {
    int size;
    vector <pair <int, int> > mins;

    void init(int n) {
        size = 1;

        while (size < n) {
            size *= 2;
        }

        mins.resize(size * 2, {INT_MAX, 1});
    }

    void build(vector <int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < v.size()) {
                mins[x].first = v[lx];
            }

            return;
        }
        else {
            int mid = lx + (rx - lx) / 2;

            build(v, 2 * x + 1, lx, mid);
            build(v, 2 * x + 2, mid, rx);

            if (mins[2 * x + 1].first < mins[2 * x + 2].first) {
                mins[x] = mins[2 * x + 1];
            }
            else if (mins[2 * x + 1].first > mins[2 * x + 2].first) {
                mins[x] = mins[2 * x + 2];
            }
            else {
                mins[x].first = mins[2 * x + 1].first;

                mins[x].second = mins[2 * x + 1].second + mins[2 * x + 2].second;
            }
        }
    }

    void build(vector <int> &v) {
        init(v.size());

        build(v, 0, 0, size);
    }

    void set(int i, int v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            mins[x].first = v;

            return;
        }

        int m = lx + (rx - lx) / 2;

        if (i < m) {
            set(i, v, 2 * x + 1, lx, m);
        }
        else {
            set(i, v, 2 * x + 2, m, rx);
        }
        
        if (mins[2 * x + 1].first < mins[2 * x + 2].first) {
            mins[x] = mins[2 * x + 1];
        }
        else if (mins[2 * x + 1].first > mins[2 * x + 2].first) {
            mins[x] = mins[2 * x + 2];
        }
        else {
            mins[x].first = mins[2 * x + 1].first;

            mins[x].second = mins[2 * x + 1].second + mins[2 * x + 2].second;
        }
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }

    pair <int, int> minimum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || rx <= l) {
            return {INT_MAX, 1};
        }
        else if (lx >= l && rx <= r) {
            return mins[x];
        }
        else {
            int mid = lx + (rx - lx) / 2;

            pair min_left = minimum(l, r, 2 * x + 1, lx, mid);
            pair min_right = minimum(l, r, 2 * x + 2, mid, rx);

            pair <int, int> m;
            
            if (min_left.first < min_right.first) {
                m = min_left;
            }
            else if (min_left.first > min_right.first) {
                m = min_right;
            }
            else {
                m.first = min_left.first;

                m.second = min_left.second + min_right.second;
            }

            return m;
        }
    }

    pair <int, int> minimum(int l, int r) {
        return minimum(l, r, 0, 0, size);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    segment_tree st;

    cin >> n >> m;

    vector <int> nums(n);

    for (auto &it : nums) {
        cin >> it;
    }

    st.build(nums);

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

            pair <int, int> p = st.minimum(l, r);

            cout << p.first << " " << p.second << "\n";
        }
    }

    return 0;
}