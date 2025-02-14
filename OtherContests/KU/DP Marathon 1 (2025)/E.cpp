#include <bits/stdc++.h>

using namespace std;

int knapsack(int n, int w, int v, vector <int> &wt, vector <int> &val)
{
    int i, j, max_val = 0;
    vector <long long> dp(v + 1, 1e15);

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w, i;

    cin >> n >> w;

    vector <int> wt(n), val(n);

    for (i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }

    cout << knapsack(n, w, accumulate(val.begin(), val.end(), 0), wt, val) << "\n";

    return 0;
}