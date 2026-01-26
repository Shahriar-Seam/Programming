#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, score = 0;

    cin >> n;

    vector <int> a(n), b(n), pref(n + 1, 0);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    sort(a.begin(), a.end());

    for (i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + b[i];
    }

    for (i = 0; i < n; i++) {
        auto r = --upper_bound(pref.begin(), pref.end(), n - i) - pref.begin();

        score = max(score, a[i] * r);
    }

    cout << score << "\n";
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