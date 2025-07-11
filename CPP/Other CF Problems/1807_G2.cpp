#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, sum = 1;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end());

    if (v[0] != 1) {
        cout << "NO\n";

        return;
    }

    for (i = 1; i < n; i++) {
        if (sum < v[i]) {
            cout << "NO\n";

            return;
        }

        sum += v[i];
    }

    cout << "YES\n";
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