#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, q, i;

    cin >> n >> q;

    vector <int> v(n);
    set <int> s;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        if (v[i] > 0) {
            s.insert(i);
        }
    }

    while (q--) {
        int l, r, m;

        cin >> l >> r >> m;

        if (m == 1) {
            continue;
        }

        vector <int> temp;

        set <int>::iterator it;

        it = s.lower_bound(l - 1);

        if (it == s.end()) {
            continue;
        }

        while (it != s.end()) {
            if (*it < r) {
                v[*it] /= m;

                if (v[*it] == 0) {
                    temp.push_back(*it);
                }

                it++;
            }
            else {
                break;
            }
        }

        for (auto jt : temp) {
            s.erase(jt);
        }
    }

    for (auto it : v) {
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
        cout << "Case " << i << ": ";

        solve();
    }

    return 0;
}