#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, k, q, l, r, count = 0;

    cin >> n >> k >> q;

    vector <int> v(n);
    vector <int> consecutive_days;

    for (auto &it : v) {
        cin >> it;
    }

    for (l = -1, r = 0; r < n; r++) {
        if (v[r] > q) {
            if (l != -1 && r - l >= k) {
                consecutive_days.push_back(r - l);
            }

            l = -1;
        }
        else if (l == -1) {
            l = r;
        }
    }

    if (l != -1 && r - l >= k) {
        consecutive_days.push_back(r - l);
    }

    for (auto it : consecutive_days) {
        count += ((it - k + 1) * (it - k + 2)) / 2;
    }

    cout << count << "\n";
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