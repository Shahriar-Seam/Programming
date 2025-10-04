#include <bits/stdc++.h>

using namespace std;

const int inf = INT_MAX;

int ceil_div(int a, int b)
{
    return (a + b - 1) / b;
}

int need_to_add(int v, int j, int m)
{
    return (ceil_div(v, m) * m - v + j) % m;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, l, i, j, k;

    cin >> n >> m >> l;

    vector <int> v(n), t(l);
    vector <vector <int> > f(l, vector <int> (m, 0)), dp(l + 1, vector <int> (m, inf));

    dp[0][0] = 0;

    for (auto &it : v) {
        cin >> it;
    }

    for (i = 0; i < l; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; i + k * l < n; k++) {
                f[i][j] += need_to_add(v[i + k * l], j, m);
            }
        }
    }

    for (i = 1; i <= l; i++) {
        for (j = 0; j < m; j++) {
            if (dp[i - 1][j] != inf) {
                for (k = 0; k < m; k++) {
                    dp[i][(j + k) % m] = min(dp[i][(j + k) % m], dp[i - 1][j] + f[i - 1][k]);
                }
            }
        }
    }
    
    cout << dp[l][0] << "\n";

    return 0;
}