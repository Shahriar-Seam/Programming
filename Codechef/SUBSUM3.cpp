#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;

        it %= 3;
    }

    sort(v.begin(), v.end());

    if (v[0] == 0 || count(v.begin(), v.end(), 1) >= 3 || count(v.begin(), v.end(), 1) >= 1 && count(v.begin(), v.end(), 2) > 0 || count(v.begin(), v.end(), 2) >= 3) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
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