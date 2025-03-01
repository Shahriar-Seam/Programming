#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, f = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (gcd(v[i], v[j]) <= 2) {
                f = 1;

                break;
            }
        }
    }

    cout << (f ? "YES" : "NO") << "\n";
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