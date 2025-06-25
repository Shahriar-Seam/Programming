#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, ops = 1e9, temp;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 1, ops = v[0]; i < n; i++) {
        temp = max(0, v[i] - i + 1);

        ops = min(ops, temp + i);
    }

    cout << ops << "\n";
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