#include <bits/stdc++.h>

using namespace std;

#define int long long
const int mod = 1e9 + 7;

void solve()
{
    int n, m, count = 1, temp = 0, i;

    cin >> n >> m;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 1; i < n; i++) {
        temp = ((m - v[i]) / v[i - 1]) + 1;

        count = (count * temp) % mod;
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