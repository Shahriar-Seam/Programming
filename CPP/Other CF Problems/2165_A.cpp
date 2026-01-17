#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, sum = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    v.push_back(v[0]);

    sum -= *max_element(v.begin(), v.end());

    for (i = 0; i < n; i++) {
        sum += max(v[i], v[i + 1]);
    }

    cout << sum << "\n";
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