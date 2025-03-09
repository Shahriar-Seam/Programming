#include <bits/stdc++.h>

using namespace std;

void num_ways(int n, int k, vector <int> &occupied_row, vector <int> &occupied_col, int &count)
{
    if (k == 0) {
        count++;

        return;
    }

    for (int i = 0; i < n; i++) {
        if (!occupied_row[i] && !occupied_col[i]) {
            occupied_row[i] = occupied_col[i] = 1;
            num_ways(n, k - 1, occupied_row, occupied_col, count);
            occupied_row[i] = occupied_col[i] = 0;
            num_ways(n, k - 1, occupied_row, occupied_col, count);
        }
    }
}

void solve()
{
    int i, n, k, count = 0;

    cin >> n >> k;

    if (k > n) {
        cout << "0\n";

        return;
    }

    cout << tgamma(n + 1) / (tgamma(k) * tgamma(k + 1)) << "\n";
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