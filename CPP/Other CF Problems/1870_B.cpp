#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, o = 0, mn = 0, mx = 0;

    cin >> n >> m;

    vector <int> a(n), b(m);

    for (auto &it : a) {
        cin >> it;

        mn ^= it;
    }

    for (auto &it : b) {
        cin >> it;

        o |= it;
    }

    for (auto &it : a) {
        it |= o;

        mx ^= it;
    }

    
    if (mn > mx) {
        swap(mn, mx);
    }

    cout << mn << " " << mx << "\n";
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