#include <bits/stdc++.h>

using namespace std;

struct item {
    int data;
    int index;
};

struct segment_tree {
    int size;
    vector <item> hotels;

    item NEUTRAL_ELEMENT = {0, -1};

    item operation(item a, item b) {
        if (a.data > b.data) {
            return a;
        }
        else if (b.data > a.data) {
            return b;
        }
        else {
            if (a.index < b.index) {
                return a;
            }
            else {
                return b;
            }
        }
    }

    void init(int n) {
        size = 1;

        while (size < n) {
            size *= 2;
        }

        hotels.resize(size * 2, NEUTRAL_ELEMENT);
    }

    void build(vector <int> &v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            if (lx < v.size()) {
                hotels[x] = {v[lx], lx};
            }
            
            return;
        }
        
        int mid = (lx + rx) / 2;

        build(v, 2 * x + 1, lx, mid);
        build(v, 2 * x + 2, mid, rx);

        hotels[x] = operation(hotels[2 * x + 1], hotels[2 * x + 2]);
    }

    void build(vector <int> &v) {
        init(v.size());

        build(v, 0, 0, size);
    }

    int get(int r, int x, int lx, int rx) {
        if (hotels[x].data < r) {
            return -1;
        }

        if (rx - lx == 1) {
            hotels[x].data -= r;

            return hotels[x].index;
        }

        int mid = (lx + rx) / 2;

        item left = hotels[2 * x + 1];
        item right = hotels[2 * x + 2];
        int index = 0;

        if (left.data >= r) {
            index = get(r, 2 * x + 1, lx, mid);
        }
        else {
            index = get(r, 2 * x + 2, mid, rx);
        }

        hotels[x] = operation(hotels[2 * x + 1], hotels[2 * x + 2]);

        return index;
    }

    int get(int r) {
        return get(r, 0, 0, size);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    segment_tree st;

    cin >> n >> m;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    st.build(v);

    while (m--) {
        int r;

        cin >> r;

        cout << st.get(r) + 1 << " ";
    }

    return 0;
}