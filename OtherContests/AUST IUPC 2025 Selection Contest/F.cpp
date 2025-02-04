#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve()
{
    int n, m, cost = 0, unavailable = 0, i;

    cin >> n >> m;

    vector <int> k(n), c(m);

    for (auto &it : k) {
        cin >> it;
    }

    for (auto &it : c) {
        cin >> it;
    }

    sort(k.begin(), k.end(), greater <int> ());

    for (i = 0; i < n; i++) {
        if (unavailable < k[i]) {
            if (c[unavailable] >= c[k[i] - 1]) {
                cost += c[k[i] - 1];
            }
            else {
                cost += c[unavailable];

                unavailable++;
            }
        }
        else {
            cost += c[k[i] - 1];
        }
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