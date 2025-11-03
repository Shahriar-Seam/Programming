#include <bits/stdc++.h>

using namespace std;

#define int long long

const int inf = 1e9;

int high(vector <int> &t, int k)
{
    int l = 0, r = t.size() - 1, m, index;

    while (l <= r) {
        m = (l + r) / 2;

        if (t[m] >= k) {
            index = m;

            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    return index;
}

int low(vector <int> &t, int k)
{
    int l = 0, r = t.size() - 1, m, index;

    while (l <= r) {
        m = (l + r) / 2;

        if (t[m] <= k) {
            index = m;

            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    return index;
}

struct item {
    int s, c;
};

struct segment_tree {
    int size;
    vector <item> values;

    // Change it
    item NEUTRAL_ELEMENT = {0, 0};

    // Change it
    item merge(item a, item b) {
        item c;

        c.s = a.s + b.s;
        c.c = a.c + b.c;

        return c;
    }

    // Change it
    item single(int v) {
        return {v, (v != 0)};
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

string to_string(__int128_t n)
{
    string s;
    int sign = 0;

    if (n == 0) {
        s = "0";
    }

    if (n < 0) {
        sign = 1;

        n = -n;
    }

    while (n) {
        s.push_back(n % 10 + '0');

        n = n / 10;
    }

    if (sign) {
        s.push_back('-');
    }

    reverse(s.begin(), s.end());

    return s;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, i, l, r;
    __int128_t sum = 0;
    multiset <int> ms;
    segment_tree st;
    map <int, queue <int> > indices;

    cin >> n;

    vector <int> v(n), pref(n + 1, 0), t;

    for (auto &it : v) {
        cin >> it;

        ms.insert(it);
    }

    t = v;

    sort(t.begin(), t.end());

    for (i = 0; i < n; i++) {
        indices[t[i]].push(i);
    }

    st.build(t);

    for (i = 0; i < n; i++) {
        if (*ms.begin() <= v[i] - 2) {
            l = low(t, v[i] - 2);
        }
        else {
            l = -inf;
        }

        if (*prev(ms.end()) >= v[i] + 2) {
            r = high(t, v[i] + 2);
        }
        else {
            r = inf;
        }

        if (l >= 0) {
            auto l_t = st.calculate(0, l + 1);

            sum = sum - l_t.c * v[i];

            sum = sum + l_t.s;
        }

        if (r < inf) {
            auto r_t = st.calculate(r, n);

            sum = sum - r_t.c * v[i];

            sum = sum + r_t.s;
        }

        auto index = indices[v[i]].front();
        st.set(index, 0);

        indices[v[i]].pop();
        ms.erase(ms.find(v[i]));
    }

    cout << to_string(sum) << "\n";

    return 0;
}