#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i, f = 1;
    map <int, int> mp_b, mp_d;

    cin >> n;

    vector <int> a(n), b(n), d;

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    cin >> m;

    d.resize(m);

    for (auto &it : d) {
        cin >> it;

        mp_d[it]++;
    }

    for (i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            mp_b[b[i]]++;
        }
    }

    for (auto it : mp_b) {
        if (mp_d[it.first] < it.second) {
            f = 0;
        }
    }

    cout << (f && count(b.begin(), b.end(), d.back()) > 0 ? "YES" : "NO") << "\n";
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