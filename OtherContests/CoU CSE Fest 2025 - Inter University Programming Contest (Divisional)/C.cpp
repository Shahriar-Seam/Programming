#include <bits/stdc++.h>

using namespace std;

struct Tree {
    typedef int T;

    static constexpr T unit = 0;

    T f(T a, T b) {
        return gcd(a, b);
    }

    vector <T> s;
    int n;

    Tree (int n = 0, T def = unit) : n(n), s(2 * n, def) {}

    void build(vector <T> &a) {
        for (int i = 0; i < n; i++) {
            s[i + n] = a[i];
        }

        for (int i = n - 1; i > 0; i--) {
            s[i] = f(s[i * 2], s[i * 2 + 1]);
        }
    }

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

const int sz = 2e5 + 5;
vector <bool> marked(sz, true);
vector <int> primes;

void sieve()
{
    int i, j;

    for (i = 3; i * i < sz; i += 2) {
        if (marked[i]) {
            for (j = i * i; j < sz; j += 2 * i) {
                marked[j] = false;
            }
        }
    }

    primes.push_back(2);

    for (i = 4; i < sz; i += 2) {
        marked[i] = false;
    }

    marked[2] = true;
    marked[1] = false;

    for (i = 3; i < sz; i += 2) {
        if (marked[i]) {
            primes.push_back(i);
        }
    }
}

void solve()
{
    int n, l, r, len = -1;

    cin >> n;

    vector <int> v(n);
    Tree t(n);

    for (auto &it : v) {
        cin >> it;
    }

    t.build(v);

    for (l = 0, r = 0; r < n; r++) {
        while (t.query(l, r + 1) == 1) {
            l++;
        }

        if (marked[t.query(l, r + 1)]) {
            len = max(len, r - l + 1);
        }
    }

    if (len == 0) {
        len = -1;
    }

    cout << len << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}