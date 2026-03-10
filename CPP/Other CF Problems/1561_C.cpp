#include <bits/stdc++.h>

using namespace std;

bool possible(vector <vector <int> > &v, int p)
{
    for (auto &it : v) {
        for (auto &jt : it) {
            if (jt < p) {
                p++;
            }
            else {
                return false;
            }
        }
    }

    return true;
}

void solve()
{
    int n, i = 0, k, mx;
    int l = 0, r = 1e9 + 5, m, p;

    cin >> n;

    vector <vector <int> > v(n);

    for (auto &it : v) {
        cin >> k;

        it.resize(k);
        mx = 0;

        for (auto &jt : it) {
            cin >> jt;

            mx = max(mx + 1, jt + 1);
        }

        it.push_back(mx - k);
    }

    sort(v.begin(), v.end(), [&] (vector <int> &a, vector <int> &b) {
        return a.back() < b.back();
    });

    for (auto &it : v) {
        it.pop_back();
    }

    while (l <= r) {
        m = (l + r) / 2;

        if (possible(v, m)) {
            p = m;

            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    cout << p << "\n";
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