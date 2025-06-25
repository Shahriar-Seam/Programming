#include <bits/stdc++.h>

using namespace std;

#define int long long

bool possible(vector <int> &v, int n, int m)
{
    int i, count = 0;

    for (i = 0; i < n; i++) {
        if (v[i] > m) {
            m--;
        }
    }

    return m >= 0;
}

void solve()
{
    int n, l, r, m, time = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end(), greater <> ());

    l = 1, r = 1e17, m;

    while (l <= r) {
        m = (l + r) / 2;

        if (possible(v, n, m)) {
            time = m;

            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    cout << time << "\n";
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