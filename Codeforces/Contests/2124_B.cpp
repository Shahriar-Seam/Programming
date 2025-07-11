#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, c_min, i;

    cin >> n;

    vector <int> v(n + 1, 0), sums(n, 0), p(n, 0);

    for (i = 0; i < n; i++) {
        cin >> v[i];
    }

    c_min = v[0];

    sums[0] = v[0] + v[1];
    p[0] = v[0];

    for (i = 1; i < n; i++) {
        sums[i] = p[i - 1] + min(c_min, v[i] + v[i + 1]);

        c_min = min(c_min, v[i]);
        p[i] = p[i - 1] + c_min;
    }

    cout << *min_element(sums.begin(), sums.end()) << "\n";
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