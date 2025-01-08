#include <bits/stdc++.h>

using namespace std;

#define int long long

int knapsack(int n, int w, vector <int> &wt, vector <int> &val)
{
    int i, j;
    vector <int> dp(w + 1, 0);

    for (i = 0; i < n; i++) {
        for (j = w; j >= wt[i]; j--) {
            dp[j] = max(dp[j], dp[j - wt[i]] + val[i]);
        }
    }

    return dp[w];
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w, i;

    cin >> n >> w;

    vector <int> wt(n), val(n);

    for (i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }

    cout << knapsack(n, w, wt, val) << "\n";

    return 0;
}