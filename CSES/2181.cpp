#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

void recurse(int i, int n, int current, int next, vector <int> &masks)
{
    if (i == n) {
        masks.push_back(next);

        return;
    }

    if (current & (1 << i))  {
        recurse(i + 1, n, current, next, masks);
    }
    if ((i + 1 < n) && !((current & (1 << i)) | (current & (1 << (i + 1))))) {        
        recurse(i + 2, n, current | (1 << i) | (1 << (i + 1)), next, masks);
    }
    if (!(current & (1 << i))) {
        recurse(i + 1, n, current | (1 << i), next | (1 << i), masks);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, _n, col, current_mask = 0;

    cin >> n >> m;

    _n = 1 << n;

    vector <vector <int> > dp(m + 1, vector <int> (_n, 0));

    dp[0][0] = 1;

    for (col = 0; col < m; col++) {
        for (current_mask = 0; current_mask < _n; current_mask++) {
            if (dp[col][current_mask]) {
                vector <int> masks;

                recurse(0, n, current_mask, 0, masks);

                for (auto &next_mask : masks) {
                    dp[col + 1][next_mask] = (dp[col + 1][next_mask] + dp[col][current_mask]) % mod;
                }
            }
        }
    }

    cout << dp[m][0] << "\n";

    return 0;
}