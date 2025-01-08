#include <bits/stdc++.h>

using namespace std;

int knapsack(int n, int m, vector <int> &w, vector <int> &d)
{
    int i, j;
    vector <int> dp(m + 1, 0);

    for (i = 0; i < n; i++) {
        for (j = m; j >= w[i]; j--) {
            dp[j] = max(dp[j], dp[j - w[i]] + d[i]);
        }
    }

    return dp[m];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, i;

    cin >> n >> m;

    vector <int> w(n), d(n);

    for (i = 0; i < n; i++) {
        cin >> w[i] >> d[i];
    }

    cout << knapsack(n, m, w, d) << "\n";

    return 0;
}