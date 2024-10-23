#include <bits/stdc++.h>

using namespace std;

typedef struct {
    long long mod[3] = {1, 0, 0};
    long long prop = 0;
} item;

struct segment_tree {
    vector <item> values;
    int size;

    item NEUTRAL_ELEMENT = {{1, 0, 0}, 0};

    void init(int n) {
        size = 1;

        while (size < n) {
            size *= 2;
        }

        values.resize(2 * size, NEUTRAL_ELEMENT);
    }

    void build(int x, int lx, int rx) {
        if (rx - lx == 1) {
            values[x] = NEUTRAL_ELEMENT;

            return;
        }

        int mid = (lx + rx) / 2;

        build(2 * x + 1, lx, mid);
        build(2 * x + 2, mid, rx);

        values[x].mod[0] = values[2 * x + 1].mod[0] + values[2 * x + 2].mod[0];
    }

    void build(int n) {
        init(n);

        build(0, 0, size);
    }

    void update(int l, int r, int v, int x, int lx, int rx) {
        if (values[x].prop) {
            if (values[x].prop == 1) {
                long long temp = values[x].mod[0];
                values[x].mod[0] = values[x].mod[2];
                values[x].mod[2] = values[x].mod[1];
                values[x].mod[1] = temp;
            }
            else {
                long long temp = values[x].mod[0];
                values[x].mod[0] = values[x].mod[1];
                values[x].mod[1] = values[x].mod[2];
                values[x].mod[2] = temp;
            }

            if (rx - lx > 1) {
                values[2 * x + 1].prop += values[x].prop;
                values[2 * x + 2].prop += values[x].prop;

                values[2 * x + 1].prop %= 3;
                values[2 * x + 2].prop %= 3;
            }
            values[x].prop = 0;
        }
        if (lx >= r || rx <= l) {
            return;
        }
        if (lx >= l && rx <= r) {
            long long temp = values[x].mod[0];
            values[x].mod[0] = values[x].mod[2];
            values[x].mod[2] = values[x].mod[1];
            values[x].mod[1] = temp;

            if (rx - lx > 1) {
                values[2 * x + 1].prop += 1;
                values[2 * x + 2].prop += 1;

                values[2 * x + 1].prop %= 3;
                values[2 * x + 2].prop %= 3;
            }

            return;
        }

        int mid = (lx + rx) / 2;

        update(l, r, v, 2 * x + 1, lx, mid);
        update(l, r, v, 2 * x + 2, mid, rx);

        values[x].mod[0] = values[2 * x + 1].mod[0] + values[2 * x + 2].mod[0];
        values[x].mod[1] = values[2 * x + 1].mod[1] + values[2 * x + 2].mod[1];
        values[x].mod[2] = values[2 * x + 1].mod[2] + values[2 * x + 2].mod[2];
    }

    void update(int l, int r, int v) {
        update(l, r, v, 0, 0, size);
    }

    long long query(int l, int r, int x, int lx, int rx) {
        if (values[x].prop) {
            if (values[x].prop == 1) {
                long long temp = values[x].mod[0];
                values[x].mod[0] = values[x].mod[2];
                values[x].mod[2] = values[x].mod[1];
                values[x].mod[1] = temp;
            }
            else {
                long long temp = values[x].mod[0];
                values[x].mod[0] = values[x].mod[1];
                values[x].mod[1] = values[x].mod[2];
                values[x].mod[2] = temp;
            }

            if (rx - lx > 1) {
                values[2 * x + 1].prop += values[x].prop;
                values[2 * x + 2].prop += values[x].prop;

                values[2 * x + 1].prop %= 3;
                values[2 * x + 2].prop %= 3;
            }

            values[x].prop = 0;
        }
        if (lx >= r || rx <= l) {
            return 0;
        }
        if (lx >= l && rx <= r) {
            return values[x].mod[0];
        }

        int mid = (lx + rx) / 2;

        return query(l, r, 2 * x + 1, lx, mid) + query(l, r, 2 * x + 2, mid, rx);
    }

    long long query(int l, int r) {
        return query(l, r, 0, 0, size);
    }

    void show() {
        int i, j, k = 0;

        for (i = 0, j = 0; i <= log2(size); i++) {
            for (j = 0; j < (1 << i); j++) {
                cout << values[k++].mod[0] << " ";
            }

            cout << "\n";
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c;
    segment_tree st;

    cin >> n >> c;

    st.build(n);

    while (c--) {
        int op;

        cin >> op;

        if (op == 0) {
            int a, b;

            cin >> a >> b;

            st.update(a, b + 1, 1);
        }
        else {
            int a, b;

            cin >> a >> b;

            cout << st.query(a, b + 1) << "\n";
        }
    }

    return 0;
}