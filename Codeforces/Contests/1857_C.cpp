#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j;

    cin >> n;

    vector <int> v((n * (n - 1)) / 2), a;

    for (auto &it : v) {
        cin >> it;
    }

    sort(v.begin(), v.end(), greater <> ());

    for (i = 0, j = 1; i < v.size(); i += j, j++) {
        cout << v[i] << " ";
    }

    cout << v[0] << "\n";
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