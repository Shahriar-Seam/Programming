#include <bits/stdc++.h>

using namespace std;

int knapsack(int x, vector <int> &h, vector <int> &s, int index, vector <vector <int> > &dp)
{
    if (index < 0) {
        return 0;
    }

    if (dp[index][x] != -1) {
        return dp[index][x];
    }

    if (h[index] > x) {
        dp[index][x] = knapsack(x, h, s, index - 1, dp);
    }
    else {
        dp[index][x] = max(knapsack(x, h, s, index - 1, dp), s[index] + knapsack(x - h[index], h, s, index - 1, dp));
    }

    return dp[index][x];
}

int knapsack(int x, vector <int> &h, vector <int> &s)
{
    int n = h.size();

    vector <vector <int> > dp(n, vector <int> (x + 1, -1));

    return knapsack(x, h, s, n - 1, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;

    cin >> n >> x;

    vector <int> h(n), s(n);

    for (auto &it : h) {
        cin >> it;
    }

    for (auto &it : s) {
        cin >> it;
    }

    cout << knapsack(x, h, s) << "\n";

    return 0;
}