#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, m, i;

    cin >> n >> m;

    vector <int> a(n), b(m);

    for (auto &it : a) {
        cin >> it;
    }
    for (auto &it : b) {
        cin >> it;
    }

    sort(b.begin(), b.end());
    reverse(a.begin(), a.end());

    for (i = 1; i < n; i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i] + a[i - 1]);

        if (it == b.end()) {
            it--;

            if (*it > a[i] + a[i - 1]) {
                continue;
            }
            else {
                a[i] = *it - a[i];
            }
        }
        else if (it == b.begin()) {
            if (*it > a[i] + a[i - 1]) {
                continue;
            }
            else {
                a[i] = *it - a[i];
            }
        }
        else if (*it > a[i] + a[i - 1]) {
            it--;

            if (*it > a[i] + a[i - 1]) {
                continue;
            }
            else {
                a[i] = *it - a[i];
            }
        }
        else {
            a[i] = *it - a[i];
        }
    }

    cout << (is_sorted(a.rbegin(), a.rend()) ? "YES" : "NO") << "\n";
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