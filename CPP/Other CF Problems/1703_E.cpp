#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, i, j, total_ops = 0, one = 0;

    cin >> n;

    vector <string> v(n);

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < n / 2; i++) {
        for (j = i; j < n - i - 1; j++) {
            one = 0;
            
            one += (v[i][j] == '1');
            one += (v[j][n - i - 1] == '1');
            one += (v[n - i - 1][n - j - 1] == '1');
            one += (v[n - j - 1][i] == '1');

            total_ops += min(one, 4 - one);
        }
    }

    cout << total_ops << "\n";
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