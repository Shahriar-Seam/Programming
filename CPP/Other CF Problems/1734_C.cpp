#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, i, j, total_cost = 0;
    string s;

    cin >> n >> s;

    vector <bool> v(n + 1, false);
    vector <int> cost(n + 1, 0);

    for (i = 0; i < n; i++) {
        v[i + 1] = (s[i] == '1');
    }

    for (i = n; i >= 1; i--) {
        for (j = i; j <= n; j += i) {
            if (v[j]) {
                break;
            }

            cost[j] = i;
        }
    }

    for (i = 1; i <= n; i++) {
        if (!v[i]) {
            total_cost += cost[i];
        }
    }

    cout << total_cost << "\n";
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