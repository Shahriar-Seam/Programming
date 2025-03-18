#include <bits/stdc++.h>

using namespace std;

#define int long long

int bin_search(vector <int> &v, int k)
{
    int l = 0, r = v.size() - 1, m, index = -1;

    while (l <= r) {
        m = l + (r - l) / 2;

        if (v[m] >= k) {
            index = m;
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }

    return index;
}

void solve()
{
    int n, m, i, sum = 0, total_sum = 0, r, cnt;

    cin >> n >> m;

    vector <int> v(m), pref(m + 1, 0);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    for (i = 0; i < m; i++) {
        if (v[i] >= n) {
            v[i] = n - 1;
        }
    }

    for (i = 0; i < m; i++) {
        pref[i + 1] = pref[i] + v[i];
    }

    for (i = 0; i < m - 1; i++) {
        r = bin_search(v, n - v[i]);

        if (r != -1) {
            r = max(i + 1, r);

            total_sum = pref[m] - pref[r];
            cnt = m - r;

            sum += (v[i] * cnt + total_sum - n * cnt + cnt) * 2;
        }
    }

    cout << sum << "\n";
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