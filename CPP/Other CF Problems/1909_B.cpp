#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, k;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (k = 1; k <= 60; k++) {
        set <int> s;

        for (auto &it : v) {
            s.insert(it % (1LL << k));
        }

        if (s.size() == 2) {
            cout << (1LL << k) << "\n";

            return;
        }
    }

    cout << "-1\n";
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