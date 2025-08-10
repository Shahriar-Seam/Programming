#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, f = 1;
    map <int, int> mp_s, mp_t;

    cin >> n >> k;

    vector <int> s(n), t(n);

    for (auto &it : s) {
        cin >> it;

        it %= k;

        mp_s[it]++;
    }

    for (auto &it : t) {
        cin >> it;

        it %= k;

        mp_t[it]++;
    }

    for (auto &it : mp_s) {
        if (mp_s[it.first] + mp_s[k - it.first] != mp_t[it.first] + mp_t[k - it.first]) {
            f = 0;

            break;
        }
    }

    cout << (f ? "YES" : "NO") << "\n";
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