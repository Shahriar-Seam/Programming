#include <bits/stdc++.h>

using namespace std;

const int sz = 1e5 + 5;

array <vector <int>, 2> manacher(vector <int> &v)
{
    int n = v.size();

    array <vector <int>, 2> p = {vector <int> (n + 1), vector <int> (n)};

    for (int z = 0; z < 2; z++) {
        for (int i = 0, l = 0, r = 0; i < n; i++) {
            int t = r - i + !z;

            if (i < r) {
                p[z][i] = min(t, p[z][l + t]);
            }

            int L = i - p[z][i], R = i + p[z][i] - !z;

            while (L >= 1 && R + 1 < n && v[L - 1] == v[R + 1]) {
                p[z][i]++, L--, R++;
            }

            if (R > r) {
                l = L, r = R;
            }
        }
    }

    return p;
}

int mex(vector <int> &v, int l, int r)
{
    int i;
    vector <bool> visited(sz, false);

    for (i = l; i <= r; i++) {
        visited[v[i]] = true;
    }

    for (i = 0; i < sz; i++) {
        if (!visited[i]) {
            break;
        }
    }

    return i;
}

void solve()
{
    int n, i, j, l, r, max_mex = 1;

    cin >> n;

    vector <int> v(2 * n);

    for (auto &it : v) {
        cin >> it;
    }

    array <vector <int>, 2> p = manacher(v);

    for (j = 0; j < p[0].size(); j++) {
        if (p[0][j]) {
            l = j - p[0][j];
            r = j + p[0][j] - 1;

            max_mex = max(max_mex, mex(v, l, r));
        }
    }

    for (j = 0; j < p[1].size(); j++) {
        if (p[1][j]) {
            l = j - p[1][j];
            r = j + p[1][j];

            max_mex = max(max_mex, mex(v, l, r));
        }
    }

    cout << max_mex << "\n";
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