#include <bits/stdc++.h>

using namespace std;

#define int long long

int binary_search(vector <int> &pref, int k)
{
    int l = 0, r = pref.size() - 1, m;
    int index = -1;

    while (l <= r) {
        m = (l + r) / 2;

        if (pref[m] <= k) {
            index = m;

            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }

    return index;
}

void solve()
{
    int n, q, i, k;

    cin >> n >> q;

    vector <int> v(n), pref_sum(n, 0), pref_max(n, 0);

    for (i = 0; i < n; i++) {
        cin >> v[i];

        if (i == 0) {
            pref_sum[i] = v[0];
            pref_max[i] = v[0];
        }
        else {
            pref_sum[i] += pref_sum[i - 1] + v[i];
            pref_max[i] = max(pref_max[i - 1], v[i]);
        }
    }

    while (q--) {
        cin >> k;

        i = binary_search(pref_max, k);

        cout << (i == -1 ? 0 : pref_sum[i]) << " ";
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