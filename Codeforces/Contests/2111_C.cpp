#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, j, cost = 1e15;
    int l, r;

    cin >> n;

    vector <int> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n; ) {
        l = i;
        r = i;

        for (j = i + 1; j < n; j++) {
            if (v[i] == v[j]) {
                r = j;

                continue;
            }
            else {
                break;
            }
        }

        cost = min(cost, l * (v[i]) + (n - r - 1) * v[i]);

        i = r + 1;
    }

    cout << cost << "\n";
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