#include <bits/stdc++.h>

using namespace std;

int block_size = 100;

struct Mex {
    int sz;
    vector <int> freq;
    set <int> available;

    Mex(int n) {
        sz = n;

        freq.assign(sz, 0);

        for (int i = 0; i <= sz; i++) {
            available.insert(i);
        }
    }

    bool valid(int x) {
        return 0 <= x && x < sz;
    }

    void insert(int x) {
        if (valid(x)) {
            freq[x]++;

            if (freq[x] == 1) {
                available.erase(x);
            }
        }
    }

    void remove(int x) {
        if (valid(x)) {
            freq[x]--;

            if (freq[x] == 0) {
                available.insert(x);
            }
        }
    }

    int get_mex() {
        return *available.begin();
    }
};

struct Query {
    int l, r, index;

    Query() : l(0), r(0), index(-1) {}

    Query(int l, int r, int index) : l(l), r(r), index(index) {}

    bool operator < (const Query &q) const {
        if (l / block_size == q.l / block_size) {
            return r < q.r;
        }
        else {
            return l < q.l;
        }
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q, i;
    int l, r;

    cin >> n >> q;

    vector <int> v(n), result(q);
    vector <Query> queries(q);
    Mex mex(n);

    block_size = max(1, (int) sqrt(n));

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < q; i++) {
        cin >> l >> r;

        queries[i] = Query(l - 1, r - 1, i);
    }

    sort(queries.begin(), queries.end());

    l = 0;
    r = -1;

    for (auto &Q : queries) {
        while (l > Q.l) {
            l--;

            mex.insert(v[l]);
        }

        while (r < Q.r) {
            r++;

            mex.insert(v[r]);
        }

        while (l < Q.l) {
            mex.remove(v[l]);

            l++;
        }

        while (r > Q.r) {
            mex.remove(v[r]);

            r--;
        }

        result[Q.index] = mex.get_mex();
    }

    for (auto &it : result) {
        cout << it << "\n";
    }

    return 0;
}