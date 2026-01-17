#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, sum = 0, min_sum = 1e9;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 1; i < n; i++) {
        sum += abs(v[i] - v[i - 1]);
    }

    for (i = 0; i < n; i++) {
        if (i == 0) {
            min_sum = min(min_sum, sum - abs(v[i + 1] - v[i]));
        }
        else if (i == n - 1) {
            min_sum = min(min_sum, sum - abs(v[i] - v[i - 1]));
        }
        else {
            min_sum = min(min_sum, sum - abs(v[i + 1] - v[i]) - abs(v[i] - v[i - 1]) + abs(v[i + 1] - v[i - 1]));
        }
    }

    cout << min_sum << "\n";
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