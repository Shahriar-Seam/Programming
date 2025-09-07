#include <bits/stdc++.h>

using namespace std;

struct Tree {
    typedef int T;

    static constexpr T unit = 0;

    T f(T a, T b) {
        return a + b;
    }

    vector <T> s;
    int n;

    Tree (int n = 0, T def = unit) : n(n), s(2 * n, def) {}

    void update(int pos, T val) {
        for (s[pos += n] += val; pos /= 2; ) {
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
        }
    }

    T query(int b, int e) {
        T ra = unit, rb = unit;

        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b & 1) {
                ra = f(ra, s[b++]);
            }
            if (e & 1) {
                rb = f(s[--e], rb);
            }
        }

        return f(ra, rb);
    }
};

struct Q {
    char t;
    int u, v;

    Q (char t, int u, int v) : t(t), u(u), v(v) {}
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, i;
    char type;
    int k, x, a, b;
    map <int, int> mp;
    
    cin >> n >> q;

    vector <int> v(n);
    vector <Q> queries;

    for (auto &it : v) {
        cin >> it;

        mp[it];
    }

    while (q--) {
        cin >> type;

        if (type == '!') {
            cin >> k >> x;

            mp[x];

            queries.push_back(Q(type, k, x));
        }
        else {
            cin >> a >> b;

            mp[a];
            mp[b];

            queries.push_back(Q(type, a, b));
        }
    }

    q = queries.size();

    i = 0;

    for (auto &it : mp) {
        it.second = i++;
    }

    auto m = i;

    Tree t(m);

    for (auto &it : v) {
        t.update(mp[it], 1);
    }

    for (i = 0; i < q; i++) {
        auto qq = queries[i];

        if (qq.t == '!') {
            t.update(mp[qq.u], -1);

            t.update(mp[qq.v], 1);
        }
        else {
            cout << t.query(mp[qq.u], mp[qq.v] + 1) << "\n";
        }
    }

    return 0;
}