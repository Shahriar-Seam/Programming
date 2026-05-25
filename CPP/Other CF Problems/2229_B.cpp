#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, sum = 0, s_max = 0;

    cin >> n;

    vector <int> a(n), b(n);

    for (auto &it : a) {
        cin >> it;
    }

    for (auto &it : b) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        sum += max(a[i], b[i]);

        s_max = max(s_max, min(a[i], b[i]));
    }

    cout << sum + s_max << "\n";
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