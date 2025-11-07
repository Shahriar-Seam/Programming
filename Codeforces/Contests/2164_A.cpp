#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, x;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    cin >> x;

    cout << (*min_element(v.begin(), v.end()) <= x && x <= *max_element(v.begin(), v.end()) ? "YES" : "NO") << "\n";
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