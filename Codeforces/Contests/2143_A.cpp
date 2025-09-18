#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, l, r;

    cin >> n;

    vector <int> v(n + 1), indices(n + 1, 0);

    for (i = 1; i <= n; i++) {
        cin >> v[i - 1];

        indices[v[i - 1]] = i;
    }

    if (is_sorted(v.begin(), v.end()) || is_sorted(v.begin(), v.end(), [&] (int a, int b) {
        return a > b;
    })) {
        cout << "YES\n";

        return;
    }

    for (i = 1; i <= n; i++) {
        if (indices[i] == (i + 1) / 2 || indices[i] == n - (i - 1) / 2) {
            // bleh
        }
        else {
            cout << "NO\n";

            return;
        }
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