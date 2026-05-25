#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, pref = 0, suff = 0, max_i = -1, max_v = 0, sgn = -1;

    cin >> n;

    vector <int> v(n), b;

    for (auto &it : v) {
        cin >> it;

        pref += abs(it);

        max_v += it;
    }

    for (i = n - 1; i >= 0; i--) {
        pref -= abs(v[i]);
        
        if (v[i] > 0) {
            if (pref - v[i] + suff > max_v) {
                max_v = pref - v[i] + suff;
                max_i = i;
            }
        }

        suff += v[i];
    }

    for (i = max_i - 1; i >= 0; i--) {
        if (v[i] * sgn < 0) {
            b.push_back(i + 1);

            sgn *= -1;
        }
    }

    if (max_i >= 0) {
        b.push_back(max_i + 1);
    }

    cout << b.size() << "\n";

    for (auto &it : b) {
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