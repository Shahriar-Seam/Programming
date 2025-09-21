#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int l, r, p, n, i, j, o = 0, f = 0;
    set <int> s;

    cin >> l >> r;

    for (i = l; i <= r; i++) {
        s.insert(i);
    }

    n = r - l + 1;

    deque <int> v;

    p = (1 << (31 - __builtin_clz((int32_t) r)));

    if (p > l) {
        for (i = p - 1, j = r - p + 1; i >= l && j > 0; i--, j--) {
            v.push_back(i);

            s.erase(i);
        }

        v.push_front(p);

        s.erase(p);

        if (s.find(0) != s.end()) {
            f = 1;
            s.erase(0);
        }
    }

    p = *s.begin();
    
    while (!s.empty()) {
        v.push_front(*s.begin());

        s.erase(s.begin());

        if (!s.empty()) {
            if (*s.begin() - p > 1) {
                if (f) {
                    v.push_front(0);

                    f = 0;
                }
            }

            p = *s.begin();
        }
    }

    if (f) {
        v.push_front(0);
    }

    for (i = l; i <= r; i++) {
        o += (v[i - l] | i);
    }

    cout << o << "\n";

    for (auto &it : v) {
        cout << it << " ";
    }

    cout << "\n";
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int32_t t, i;

    cin >> t;

    for (i = 1; i <= t; i++) {
        // cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}