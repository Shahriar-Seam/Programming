#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, i, j, k;
    string s = "vika";

    cin >> n >> m;

    vector <string> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0, k = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (v[j][i] == s[k]) {
                k++;

                break;
            }
        }
    }

    cout << (k == 4 ? "YES" : "NO") << "\n";
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