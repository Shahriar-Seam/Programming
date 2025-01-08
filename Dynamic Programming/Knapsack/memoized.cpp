#include <bits/stdc++.h>

using namespace std;

int knapsack(int w, vector <int> &wt, vector <int> &val, int index, vector <vector <int> > &memo)
{
    if (index < 0) {
        return 0;
    }

    if (memo[index][w] != -1) {
        return memo[index][w];
    }

    if (wt[index] > w) {
        memo[index][w] = knapsack(w, wt, val, index - 1, memo);
    }
    else {
        memo[index][w] = max(knapsack(w, wt, val, index - 1, memo), val[index] + knapsack(w - wt[index], wt, val, index - 1, memo));
    }

    return memo[index][w];
}

int knapsack(int w, vector <int> &wt, vector <int> &val)
{
    int n = wt.size();

    vector <vector <int> > memo(n, vector <int> (w + 1, -1));

    return knapsack(w, wt, val, n - 1, memo);
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

    cout << knapsack(w, wt, val) << "\n";

    return 0;
}