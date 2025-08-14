#include <bits/stdc++.h>

using namespace std;

#define int long long

bool possible(vector <vector <int> > &pref, int mid, int n, int m, int k, int i, int j)
{
    pair <int, int> lu, ld, ru, rd;

    lu = {max(0LL, i - mid), max(0LL, j - mid)};
    ld = {min(n - 1, i + mid), max(0LL, j - mid)};
    ru = {max(0LL, i - mid), min(m - 1, j + mid)};
    rd = {min(n - 1, i + mid), min(m - 1, j + mid)};

    int sum = pref[rd.first][rd.second];

    if (lu.first > 0 && lu.second > 0) {
        sum += pref[lu.first - 1][lu.second - 1];
    }

    if (ld.second > 0) {
        sum -= pref[ld.first][ld.second - 1];
    }

    if (ru.first > 0) {
        sum -= pref[ru.first - 1][ru.second];
    }

    return sum >= k + 1;
}

void solve()
{
    int n, m, k, i, j;
    int l, r, mid, dist = 1e9;

    cin >> n >> m >> k;

    vector <vector <int> > v(n, vector <int> (m)), pref(n, vector <int> (m, 0));

    for (auto &it : v) {
        for (auto &jt : it) {
            cin >> jt;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            pref[i][j] = v[i][j] + (j > 0 ? pref[i][j - 1] : 0) + (i > 0 ? pref[i - 1][j] : 0) - (i > 0 && j > 0 ? pref[i - 1][j - 1] : 0);
        }
    }

    if (pref[n - 1][m - 1] < k + 1) {
        cout << -1 << "\n";

        return;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (v[i][j]) {
                l = 0;
                r = max(n, m);

                while (l <= r) {
                    mid = (l + r) / 2;

                    if (possible(pref, mid, n, m, k, i, j)) {
                        dist = min(dist, mid);

                        r = mid - 1;
                    }
                    else {
                        l = mid + 1;
                    }
                }
            }
        }
    }

    cout << dist << "\n";
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