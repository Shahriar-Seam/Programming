#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, neg = 0;

    cin >> n >> m;

    vector <int> v(n * m);

    for (auto &it : v) {
        cin >> it;

        neg += (it < 0);

        it = abs(it);
    }

    if (neg & 1) {
        cout << accumulate(v.begin(), v.end(), 0) - 2 * *min_element(v.begin(), v.end()) << "\n";
    }
    else {
        cout << accumulate(v.begin(), v.end(), 0) << "\n";
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