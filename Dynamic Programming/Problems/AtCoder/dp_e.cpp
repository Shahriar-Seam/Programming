#include <bits/stdc++.h>

using namespace std;

#define int long long
#define inf 1e18L + 5

int knapsack(int n, int w, int v, vector <int> &wt, vector <int> &val)
{
    int i, j, max_val = 0;
    vector <int> dp(v + 1, inf);
    // min weight for val i

    dp[0] = 0;

    for (i = 0; i < n; i++) {
        for (j = v; j >= val[i]; j--) {
            dp[j] = min(dp[j], dp[j - val[i]] + wt[i]);
        }
    }

    for (i = 0; i <= v; i++) {
        if (dp[i] <= w) {
            max_val = i;
        }
    }

    return max_val;
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

    cout << knapsack(n, w, accumulate(val.begin(), val.end(), 0LL), wt, val) << "\n";

    return 0;
}