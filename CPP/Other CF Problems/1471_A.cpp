#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, x, sum = 0;

    cin >> n >> x;

    vector <int> v(n);

    for (auto &it: v) {
        cin >> it;
    }

    for (auto it : v) {
        sum += (it + x - 1) / x;
    }

    cout << (accumulate(v.begin(), v.end(), 0LL) + x - 1) / x << " " << sum << "\n";
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