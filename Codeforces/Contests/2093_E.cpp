#include <bits/stdc++.h>

using namespace std;

#define int long long

set <int> missing;

int _mex(vector <int> &v)
{
    set <int> s;
    int i = 0;

    for (auto it : v) {
        s.insert(it);
    }

    for (auto it : s) {
        if (i != it) {
            return i;
        }

        i++;
    }

    return i;
}

int possible(vector <int> &v, int m, int mex)
{
    int cnt = 0, i, j;

    for (i = 0; i < v.size(); i++) {
        if (v[i] < m) {
            missing.erase(v[i]);
        }

        if (*missing.begin() == m) {
            cnt++;

            for (j = 0; j < m; j++) {
                missing.insert(j);
            }
        }
    }

    for (j = 0; j < m; j++) {
        missing.insert(j);
    }

    return cnt;
}

void solve()
{
    int n, k, mex, i;
    int l = 0, r, m, x;

    cin >> n >> k;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    r = mex = _mex(v);

    for (i = 0; i <= mex; i++) {
        missing.insert(i);
    }

    while (l <= r) {
        m = (l + r) / 2;

        if (possible(v, m, mex) >= k) {
            x = m;

            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    cout << x << "\n";
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