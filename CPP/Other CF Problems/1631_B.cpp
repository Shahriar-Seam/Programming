#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, ops = 0;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = n - 2; i >= 0; ) {
        if (v[i] != v[n - 1]) {
            ops++;

            i = n - 1 - 2 * (n - i - 1);
        }
        else {
            i--;
        }
    }

    cout << ops << "\n";
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